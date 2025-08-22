#ifndef FFT_H
#define FFT_H

#include <stddef.h>

/*
 * Load a text data file via df_load_txt, compute radix-2 FFT on the
 * largest power-of-two segment (<= number of samples), and save the
 * magnitude spectrum to outfile using df_save_txt.
 * - If the spectrum length is smaller than DF_SIZE, the remainder is zero-filled.
 * - Returns 0 on success, non-zero on failure.
 */
int fft_file_to_magnitude_txt(const char *infile, const char *outfile);

#endif /* FFT_H */

