#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

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

// 사용자 입력 함수
Complex input_complex(const char* name) {
    Complex z;
    printf("%s의 실수부 입력: ", name);
    scanf("%lf", &z.real);
    printf("%s의 허수부 입력: ", name);
    scanf("%lf", &z.imag);
    return z;
}

int main() {
    printf("복소수 계산기\n");
    printf("====================\n");

    Complex z1 = input_complex("z1");
    Complex z2 = input_complex("z2");

    Complex sum = complex_add(z1, z2);
    Complex diff = complex_sub(z1, z2);
    Complex prod = complex_mul(z1, z2);
    Complex quot = complex_div(z1, z2);
    Complex conj1 = complex_conj(z1);
    Complex conj2 = complex_conj(z2);

    printf("\n[결과 출력]\n");
    printf("z1 = "); complex_print(z1);
    printf("z2 = "); complex_print(z2);
    printf("z1 + z2 = "); complex_print(sum);
    printf("z1 - z2 = "); complex_print(diff);
    printf("z1 * z2 = "); complex_print(prod);
    printf("z1 / z2 = "); complex_print(quot);
    printf("conj(z1) = "); complex_print(conj1);
    printf("conj(z2) = "); complex_print(conj2);

    return 0;
}
