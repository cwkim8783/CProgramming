// dataframe.h
#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <stddef.h>

#define DF_SIZE    50000
#define DF_START  (-10.0f * 3.14159265358979323846f)
#define DF_END    ( 10.0f * 3.14159265358979323846f)

typedef struct {
    size_t size;    /* 샘플 개수(DF_SIZE) */
    float *data;    /* 크기 size 배열 */
    float start;    /* DF_START */
    float end;      /* DF_END */
    float step;     /* (end - start)/(size-1) */
} DataFrame;

/* 생성·해제 */
DataFrame* df_create(void);
void       df_destroy(DataFrame *df);

/* 정보 조회 */
size_t df_size(const DataFrame *df);
float  df_start(const DataFrame *df);
float  df_end  (const DataFrame *df);
float  df_step (const DataFrame *df);

/* 샘플 접근 */
float  df_get(const DataFrame *df, size_t idx);
int    df_set(DataFrame *df, size_t idx, float value);

/* 초기화/채우기 */
int df_fill_zeros     (DataFrame *df);
int df_fill_constant  (DataFrame *df, float value);
int df_fill_function  (DataFrame *df, float (*func)(float x));

/* 유틸 */
DataFrame* df_clone(const DataFrame *df);

#endif /* DATAFRAME_H */