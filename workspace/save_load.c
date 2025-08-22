// save_load.c
#include "save_load.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Text 형식 저장
 * 데이터만 순서대로 저장 (메타데이터 없음)
 */
int df_save_txt(const DataFrame *df, const char *filename)
{
    if (!df || !filename) return -1;

    FILE *fp = fopen(filename, "w");
    if (!fp) return -1;

    // 데이터 기록
    for (size_t i = 0; i < df->size; ++i) {
        if (fprintf(fp, "%f\n", df->data[i]) < 0) {
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return 0;
}

/*
 * Text 형식 로드
 * df_create()로 고정 크기 DataFrame 생성 후 데이터만 채움
 */
DataFrame* df_load_txt(const char *filename)
{
    if (!filename) return NULL;

    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    // 고정 크기 DataFrame 생성
    DataFrame *df = df_create();
    if (!df) {
        fclose(fp);
        return NULL;
    }

    // 데이터 읽기
    for (size_t i = 0; i < df->size; ++i) {
        if (fscanf(fp, "%f", &df->data[i]) != 1) {
            df_destroy(df);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return df;
}