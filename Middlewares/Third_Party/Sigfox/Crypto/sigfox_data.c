/**
  ******************************************************************************
  * @file    sigfox_data.c
  * @author  MCD Application Team
  * @brief   holds the sigfox credentials
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "sigfox_types.h"
#include "sigfox_data.h"
#include "app_sigfox.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/*Format Key*/
#define RAW_TO_INT16A(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) 0x##a, 0x##b, 0x##c, 0x##d,\
0x##e, 0x##f, 0x##g, 0x##h, 0x##i, 0x##j, 0x##k, 0x##l, 0x##m, 0x##n, 0x##o, 0x##p
#define FORMAT_KEY(...) RAW_TO_INT16A(__VA_ARGS__)

/*Format Id*/
#define RAW_TO_INT4A(a,b,c,d) 0x##d, 0x##c, 0x##b, 0x##a
#define FORMAT_ID(...) RAW_TO_INT4A(__VA_ARGS__)

/*Format Pac*/
#define RAW_TO_INT8A(a,b,c,d,e,f,g,h) 0x##a, 0x##b, 0x##c, 0x##d,\
0x##e, 0x##f, 0x##g, 0x##h
#define FORMAT_PAC(...) RAW_TO_INT8A(__VA_ARGS__)

/* External variables --------------------------------------------------------*/
#if (!defined (SIGFOX_KMS) || (SIGFOX_KMS == 0))
#if defined(__ARMCC_VERSION)
 __attribute__((section(".USER_embedded_Keys")))
#elif defined(__ICCARM__)
#pragma default_variable_attributes = @ ".USER_embedded_Keys"
#elif defined(__CC_ARM)
#pragma arm section rodata = ".USER_embedded_Keys"
#elif defined(__GNUC__)
 __attribute__((section(".USER_embedded_Keys.encrypted_sigfox_data")))
#endif

const
sfx_u8 encrypted_sigfox_data[] =
{
#ifdef FEATURE_SECURE_MODE
  0x30,0x37,0x74,0x43,0x4E,0x39,0x52,0x67,0x4D,0x54,0x74,0x5F,0x4A,0x7A,0x6B,0x38,
  0x6B,0x6E,0x61,0x56,0x36,0x34,0x4F,0x4B,0x4C,0x44,0x52,0x75,0x37,0x32,0x52,0x48,
  0x45,0x58,0x37,0x53,0x34,0x4A,0x54,0x73,0x6C,0x71,0x4D,0x00,0x00,0x00,0x00,0x00,
#else
  FORMAT_ID(SIGFOX_ID), FORMAT_PAC(SIGFOX_PAC), 0x00, 0x00, 0x00, 0x00,
  FORMAT_KEY(SIGFOX_KEY),
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
};

/* Stop placing data in specified section*/
#if defined(__ICCARM__)
#pragma default_variable_attributes =
#elif defined(__CC_ARM)
#pragma arm section code
#endif

#endif
