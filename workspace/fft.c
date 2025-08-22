#include "fft.h"
#include "dataframe.h"
#include "save_load.h"
#include "complex.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static size_t pow2_leq(size_t n)
{
    size_t p = 1;
    while ((p << 1) <= n) p <<= 1;
    return p;
}

static void bit_reverse_permute(Complex *a, size_t n)
{
    size_t j = 0;
    for (size_t i = 1; i < n; ++i) {
        size_t bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) {
            Complex tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
}

static void fft_inplace(Complex *a, size_t n)
{
    const double PI = 3.14159265358979323846;
    bit_reverse_permute(a, n);

    for (size_t len = 2; len <= n; len <<= 1) {
        double ang = -2.0 * PI / (double)len;
        Complex wlen = complex_make(cos(ang), sin(ang));
        for (size_t i = 0; i < n; i += len) {
            Complex w = complex_make(1.0, 0.0);
            for (size_t j = 0; j < len / 2; ++j) {
                Complex u = a[i + j];
                Complex v = complex_mul(a[i + j + len / 2], w);
                a[i + j] = complex_add(u, v);
                a[i + j + len / 2] = complex_sub(u, v);
                w = complex_mul(w, wlen);
            }
        }
    }
}

int fft_file_to_magnitude_txt(const char *infile, const char *outfile)
{
    if (!infile || !outfile) return -1;

    DataFrame *df = df_load_txt(infile);
    if (!df) {
        fprintf(stderr, "FFT: failed to load '%s'\n", infile);
        return -1;
    }

    size_t n_all = df_size(df);
    size_t n = pow2_leq(n_all);
    if (n < 2) {
        fprintf(stderr, "FFT: not enough samples (%zu)\n", n_all);
        df_destroy(df);
        return -1;
    }

    Complex *x = (Complex*)malloc(n * sizeof(Complex));
    if (!x) {
        df_destroy(df);
        return -1;
    }
    for (size_t i = 0; i < n; ++i) {
        x[i] = complex_make((double)df_get(df, i), 0.0);
    }

    /* Apply Hann window to reduce spectral leakage for clearer peaks */
    if (n > 1) {
        const double two_pi = 2.0 * 3.14159265358979323846;
        for (size_t i = 0; i < n; ++i) {
            double w = 0.5 * (1.0 - cos(two_pi * (double)i / (double)(n - 1)));
            x[i].real *= w;
            x[i].imag *= w;
        }
    }

    fft_inplace(x, n);

    DataFrame *out = df_create();
    if (!out) {
        free(x);
        df_destroy(df);
        return -1;
    }

    size_t out_n = df_size(out);
    size_t copy_n = (n < out_n ? n : out_n);
    for (size_t i = 0; i < copy_n; ++i) {
        double mag = sqrt(x[i].real * x[i].real + x[i].imag * x[i].imag);
        df_set(out, i, (float)mag);
    }
    for (size_t i = copy_n; i < out_n; ++i) {
        df_set(out, i, 0.0f);
    }

    int rc = df_save_txt(out, outfile);

    df_destroy(out);
    free(x);
    df_destroy(df);

    if (rc != 0) {
        fprintf(stderr, "FFT: failed to save '%s'\n", outfile);
        return -1;
    }
    return 0;
}
