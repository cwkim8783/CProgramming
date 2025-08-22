// dataframe.c
#include "dataframe.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* 생성·해제 */
DataFrame* df_create(void)
{
    DataFrame *df = malloc(sizeof(DataFrame));
    if (!df) return NULL;

    df->size  = DF_SIZE;
    df->start = DF_START;
    df->end   = DF_END;
    df->step  = (df->end - df->start) / (df->size - 1);

    df->data = malloc(df->size * sizeof(float));
    if (!df->data) {
        free(df);
        return NULL;
    }

    // 초기값은 0으로
    for (size_t i = 0; i < df->size; ++i) {
        df->data[i] = 0.0f;
    }

    return df;
}

void df_destroy(DataFrame *df)
{
    // TODO: 메모리 해제
    if (!df) return;
    free(df->data);
    free(df);
}

/* 정보 조회 */
size_t df_size(const DataFrame *df)
{
    return df ? df->size : 0;
}

float df_start(const DataFrame *df)
{
    return df ? df->start : 0.0f;
}

float df_end(const DataFrame *df)
{
    return df ? df->end : 0.0f;
}

float df_step(const DataFrame *df)
{
    return df ? df->step : 0.0f;
}

/* 샘플 접근 */
float df_get(const DataFrame *df, size_t idx)
{
    if (!df || idx >= df->size) return 0.0f;
    return df->data[idx];
}

int df_set(DataFrame *df, size_t idx, float value)
{
    if (!df || idx >= df->size) return -1;
    df->data[idx] = value;
    return 0;
}

/* 초기화/채우기 */
int df_fill_zeros(DataFrame *df)
{
    if (!df) return -1;
    for (size_t i = 0; i < df->size; ++i) {
        df->data[i] = 0.0f;
    }
    return 0;
}

int df_fill_constant(DataFrame *df, float value)
{
    if (!df) return -1;
    for (size_t i = 0; i < df->size; ++i) {
        df->data[i] = value;
    }
    return 0;
}

int df_fill_function(DataFrame *df, float (*func)(float x))
{
    if (!df || !func) return -1;
    for (size_t i = 0; i < df->size; ++i) {
        float x = df->start + i * df->step;
        df->data[i] = func(x);
    }
    return 0;
}

/* 유틸 */
DataFrame* df_clone(const DataFrame *df)
{
    if (!df) return NULL;
    DataFrame *copy = malloc(sizeof(DataFrame));
    if (!copy) return NULL;

    copy->size  = df->size;
    copy->start = df->start;
    copy->end   = df->end;
    copy->step  = df->step;

    copy->data = malloc(copy->size * sizeof(float));
    if (!copy->data) {
        free(copy);
        return NULL;
    }

    memcpy(copy->data, df->data, copy->size * sizeof(float));
    return copy;
}
