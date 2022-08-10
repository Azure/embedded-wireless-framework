/**
  ******************************************************************************
  * @file    custom_env_sensors.h
  * @author  MEMS Application Team
  * @brief   This file contains definitions for the BSP Environmental Sensors interface for custom boards
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CUSTOM_ENV_SENSORS_H__
#define __CUSTOM_ENV_SENSORS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "custom_mems_conf.h"
#include "env_sensor.h"

#ifndef USE_CUSTOM_ENV_SENSOR_HTS221_0
#define USE_CUSTOM_ENV_SENSOR_HTS221_0          1
#endif

#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
#include "hts221.h"
#endif

#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
#define CUSTOM_HTS221_0 (0)
#endif

/* Environmental Sensor instance Info */
typedef struct
{
  uint8_t Temperature;
  uint8_t Pressure;
  uint8_t Humidity;
  uint8_t LowPower;
  float   HumMaxOdr;
  float   TempMaxOdr;
  float   PressMaxOdr;
} CUSTOM_ENV_SENSOR_Capabilities_t;

typedef struct
{
  uint32_t Functions;
} CUSTOM_ENV_SENSOR_Ctx_t;

#ifndef ENV_TEMPERATURE
#define ENV_TEMPERATURE      1U
#endif
#ifndef ENV_PRESSURE
#define ENV_PRESSURE         2U
#endif
#ifndef ENV_HUMIDITY
#define ENV_HUMIDITY         4U
#endif

#define CUSTOM_ENV_FUNCTIONS_NBR    3U
#define CUSTOM_ENV_INSTANCES_NBR    (USE_CUSTOM_ENV_SENSOR_HTS221_0)

#if (CUSTOM_ENV_INSTANCES_NBR == 0)
#error "No environmental sensor instance has been selected"
#endif

int32_t CUSTOM_ENV_SENSOR_Init(uint32_t Instance, uint32_t Functions);
int32_t CUSTOM_ENV_SENSOR_DeInit(uint32_t Instance);
int32_t CUSTOM_ENV_SENSOR_GetCapabilities(uint32_t Instance, CUSTOM_ENV_SENSOR_Capabilities_t *Capabilities);
int32_t CUSTOM_ENV_SENSOR_ReadID(uint32_t Instance, uint8_t *Id);
int32_t CUSTOM_ENV_SENSOR_Enable(uint32_t Instance, uint32_t Function);
int32_t CUSTOM_ENV_SENSOR_Disable(uint32_t Instance, uint32_t Function);
int32_t CUSTOM_ENV_SENSOR_GetOutputDataRate(uint32_t Instance, uint32_t Function, float *Odr);
int32_t CUSTOM_ENV_SENSOR_SetOutputDataRate(uint32_t Instance, uint32_t Function, float Odr);
int32_t CUSTOM_ENV_SENSOR_GetValue(uint32_t Instance, uint32_t Function, float *Value);

#ifdef __cplusplus
}
#endif

#endif /* __CUSTOM_ENV_SENSORS_H__ */

