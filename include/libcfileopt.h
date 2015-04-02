/************************************************************
  Programmer : Spencer Yeh
  E-Mail     : m782123@gmail.com
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#ifndef _LIB_C_FILE_OPT_H_
#define _LIB_C_FILE_OPT_H_

int32_t
ReadFileAndSize (
  FILE           *InFile,
  int32_t        *FileSize,
  uint8_t        **InfileBuffer
  );

int32_t
ReadFileAndSizeByName (
  char           *FileName,
  int32_t        *FileSize,
  uint8_t        **InfileBuffer
  );

#endif
