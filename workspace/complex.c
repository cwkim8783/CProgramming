#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Add two complex numbers
Complex complex_add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

// Subtract two complex numbers
Complex complex_sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

// Multiply two complex numbers
Complex complex_mul(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

// Divide two complex numbers
Complex complex_div(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return (Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

// Complex conjugate
Complex complex_conj(Complex z) {
    return (Complex){z.real, -z.imag};
}

// Print complex number
void complex_print(Complex z) {
    printf("%.2f %c %.2fi\n", z.real, (z.imag < 0 ? '-' : '+'), (z.imag < 0 ? -z.imag : z.imag));
}

int main() {
    Complex z1 = {3.0, 4.0};    // 3 + 4i
    Complex z2 = {1.0, -2.0};   // 1 - 2i

    Complex sum = complex_add(z1, z2);
    Complex diff = complex_sub(z1, z2);
    Complex prod = complex_mul(z1, z2);
    Complex quot = complex_div(z1, z2);
    Complex conj1 = complex_conj(z1);
    Complex conj2 = complex_conj(z2);

    printf("z1 = ");
    complex_print(z1);

    printf("z2 = ");
    complex_print(z2);

    printf("z1 + z2 = ");
    complex_print(sum);

    printf("z1 - z2 = ");
    complex_print(diff);

    printf("z1 * z2 = ");
    complex_print(prod);

    printf("z1 / z2 = ");
    complex_print(quot);

    printf("conj(z1) = ");
    complex_print(conj1);

    printf("conj(z2) = ");
    complex_print(conj2);

    return 0;
}
