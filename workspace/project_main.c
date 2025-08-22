// @@ -2,6 +2,7 @@
#include <stdio.h>

#include "complex.h"
#include "dataframe.h"
#include "save_load.h"

void test_complex(void){
    Complex z1 = complex_make(3.0,  4.0);
// @@ -71,10 +72,40 @@ 
}
int test_dataframe(void) {
    // TODO: DataFrame 관련 테스트 코드 작성
    return 0;
}
void test_saveload(void) {
    const char *infile  = "data/data_2sin20t.txt";
    const char *outfile = "data/data_4sin20t.txt";

    // 1. 파일에서 DataFrame 로드
    DataFrame *df = df_load_txt(infile);
    if (!df) {
        fprintf(stderr, "Error: failed to load '%s'\n", infile);
        return;
    }

    // 2. 모든 샘플을 두 배로 증폭
    size_t n = df_size(df);
    for (size_t i = 0; i < n; ++i) {
        float v = df_get(df, i);
        df_set(df, i, v * 2.0f);
    }

    // 3. 결과를 새 파일에 저장
    if (df_save_txt(df, outfile) != 0) {
        fprintf(stderr, "Error: failed to save '%s'\n", outfile);
    } else {
        printf("Saved doubled data to '%s' (%zu samples)\n", outfile, n);
    }

    // 4. 메모리 해제
    df_destroy(df);
}

int main(void) {
    // test_complex();
    test_dataframe();
    // test_dataframe();
    test_saveload();


    return 0;
}