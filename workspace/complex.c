#include <stdio.h>
#include "complex.h"

// 덧셈
Complex complex_add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

// 뺄셈
Complex complex_sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

// 곱셈
Complex complex_mul(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

// 나눗셈
Complex complex_div(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return (Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

// 켤레복소수
Complex complex_conj(Complex z) {
    return (Complex){z.real, -z.imag};
}

// 복소수 출력
void complex_print(Complex z) {
    printf("%.2f %c %.2fi\n", z.real, (z.imag < 0 ? '-' : '+'), (z.imag < 0 ? -z.imag : z.imag));
}

// 사용자 입력
Complex input_complex(const char* name) {
    Complex z;
    printf("%s의 실수부 입력: ", name);
    scanf("%lf", &z.real);
    printf("%s의 허수부 입력: ", name);
    scanf("%lf", &z.imag);
    return z;
}