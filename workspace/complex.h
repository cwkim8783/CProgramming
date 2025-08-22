#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    double real;
    double imag;
} Complex;

// 연산 함수 선언
Complex complex_add(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mul(Complex a, Complex b);
Complex complex_div(Complex a, Complex b);
Complex complex_conj(Complex z);

Complex complex_make(double a, double b){
    Complex ret2 = (Complex){a,b};

    return ret2;
}

// 출력 및 입력 함수
void complex_print(Complex z);
Complex input_complex(const char* name);

#endif // COMPLEX_H