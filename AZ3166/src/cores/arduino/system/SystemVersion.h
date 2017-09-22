// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 


#ifndef __VERSION_H__
#define __VERSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
//Get the whole version string
const char* getDevkitVersion(void);

//Get major version
uint32_t getMajorVersion(void);

//Get minor version
uint32_t getMinorVersion(void);

//Get patch version
uint32_t getPatchVersion(void);

#ifdef __cplusplus
}
#endif

#endif