#include <stdio.h>

int main(void){
    int student_number = 2021440107;
    int test = 45;

    int* hello =&student_number;

    printf("안녕하세요! 제 학번은 %d 입니다!\n",student_number);

    student_number +=1;
    student_number +=200000000;

    return 0;
}