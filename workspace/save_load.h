// save_load.h
#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "dataframe.h"

/* Text 형식으로 저장/읽기 */
/* 파일에 메타데이터(size, start, end, step)와 data[]를 모두 텍스트로 기록 */
int  df_save_txt(const DataFrame *df, const char *filename);
DataFrame* df_load_txt(const char *filename);

#endif /* SAVE_LOAD_H */