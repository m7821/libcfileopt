/************************************************************
  Programmer : Spencer Yeh
  E-Mail     : m782123@gmail.com
*************************************************************/

#include <libcfileopt.h>

/*
 @ Name : ReadFileAndSizeByName ()


 @ Description : Get file size and file buffer by the file stream


 @ param *InFile - File stream

 @ param *FileSize - The file size

 @ param **InfileBuffer - File buffer


 @ return Status - Error occured.

 @ return 0 - Success.
 
*********************************************************************/
int32_t
ReadFileAndSize (
  FILE           *InFile,
  int32_t        *FileSize,
  uint8_t        **InfileBuffer
  )
{
  int32_t        Status = 0;
  
  if (InFile == NULL) {
    return -1;
  }

  Status = fseek (InFile, 0, SEEK_END);
  if (Status < 0) {
    return Status;
  }

  *FileSize = ftell (InFile);

  Status = fseek (InFile, 0, SEEK_SET);
  if (Status < 0) {
    return Status;
  }

  *InfileBuffer = malloc (*FileSize);

  fread (*InfileBuffer, 1, *FileSize, InFile);

  return 0;
}

/*
 @ Name : ReadFileAndSizeByName ()


 @ Description : Get file size and file buffer by the input name


 @ param *FileName - The file to read

 @ param *FileSize - The file size

 @ param **InfileBuffer - File buffer


 @ return Status - Error occured.

 @ return 0 - Success.
 
*********************************************************************/
int32_t
ReadFileAndSizeByName (
  char           *FileName,
  int32_t        *FileSize,
  uint8_t        **InfileBuffer
  )
{
  int32_t        Status = 0;
  FILE           *InFile;
  
  InFile = fopen (FileName, "rb");

  Status = ReadFileAndSize (InFile, FileSize, InfileBuffer);
  if (Status)
    return Status;

  fclose (InFile);

  return 0;
}
