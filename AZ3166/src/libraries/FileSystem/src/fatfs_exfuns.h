/**
******************************************************************************
* @file    fatfs_exfuns.h
* @author  Ding QQ
* @version V1.0.0
* @date    21-May-2015
* @brief   MiCO RTOS Fatfs extern functin.
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __FATFS_EXFUNS_H
#define __FATFS_EXFUNS_H 

#include "ff.h"
#include "stdint.h"

typedef struct _filesystem_info_t {
  int total_space;
  int free_space;
  char unit;
} filesystem_info;

filesystem_info fatfs_get_info();

#endif

#ifdef __cplusplus
} /*extern "C" */
#endif