/**
 ******************************************************************************
 * @file    custom_env_sensors_ex.c
 * @author  MEMS Application Team
 * @brief   This file provides BSP Environmental Sensors Extended interface for custom boards
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Software License Agreement SLA0077,
 * the "License". You may not use this component except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        www.st.com/sla0077
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "custom_env_sensors_ex.h"

extern void *EnvCompObj[CUSTOM_ENV_INSTANCES_NBR];

/**
 * @brief  Get the register value
 * @param  Instance the device instance
 * @param  Reg address to be read
 * @param  Data pointer where the value is written to
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Read_Register(uint32_t Instance, uint8_t Reg, uint8_t *Data)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      if (HTS221_Read_Reg(EnvCompObj[Instance], Reg, Data) != BSP_ERROR_NONE)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
      else
      {
        ret = BSP_ERROR_NONE;
      }
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set the register value
 * @param  Instance the device instance
 * @param  Reg address to be read
 * @param  Data value to be written
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Write_Register(uint32_t Instance, uint8_t Reg, uint8_t Data)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      if (HTS221_Write_Reg(EnvCompObj[Instance], Reg, Data) != BSP_ERROR_NONE)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
      else
      {
        ret = BSP_ERROR_NONE;
      }
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get the status of data ready bit
 * @param  Instance the device instance
 * @param  Function Environmental sensor function
 * @param  Status the pointer to the status
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Get_DRDY_Status(uint32_t Instance, uint32_t Function, uint8_t *Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      if ((Function & ENV_HUMIDITY) == ENV_HUMIDITY)
      {
        if (HTS221_HUM_Get_DRDY_Status(EnvCompObj[Instance], Status) != BSP_ERROR_NONE)
        {
          ret = BSP_ERROR_COMPONENT_FAILURE;
        }
        else
        {
          ret = BSP_ERROR_NONE;
        }
      }
      else if ((Function & ENV_TEMPERATURE) == ENV_TEMPERATURE)
      {
        if (HTS221_TEMP_Get_DRDY_Status(EnvCompObj[Instance], Status) != BSP_ERROR_NONE)
        {
          ret = BSP_ERROR_COMPONENT_FAILURE;
        }
        else
        {
          ret = BSP_ERROR_NONE;
        }
      }
      else
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get the data stored in FIFO
 * @param  Instance the device instance
 * @param  Press the pressure data
 * @param  Temp the temperature data
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Get_Data(uint32_t Instance, float *Press, float *Temp)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get FIFO THR status
 * @param  Instance the device instance
 * @param  Status the pointer to the status
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Get_Fth_Status(uint32_t Instance, uint8_t *Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get FIFO Full status
 * @param  Instance the device instance
 * @param  Status the pointer to the status
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Get_Full_Status(uint32_t Instance, uint8_t *Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get the number of unread samples in FIFO
 * @param  Instance the device instance
 * @param  NumSamples the number of unread FIFO samples
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Get_Num_Samples(uint32_t Instance, uint8_t *NumSamples)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get FIFO OVR status
 * @param  Instance the device instance
 * @param  Status the pointer to the status
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Get_Ovr_Status(uint32_t Instance, uint8_t *Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Reset FIFO Interrupt
 * @param  Instance the device instance
 * @param  Interrupt FIFO interrupt. Could be: FTH, FULL or OVR
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Reset_Interrupt(uint32_t Instance, uint8_t Interrupt)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set FIFO Interrupt
 * @param  Instance the device instance
 * @param  Interrupt FIFO interrupt. Could be: FTH, FULL or OVR
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Set_Interrupt(uint32_t Instance, uint8_t Interrupt)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set FIFO mode
 * @param  Instance the device instance
 * @param  Mode FIFO mode
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Set_Mode(uint32_t Instance, uint8_t Mode)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set FIFO watermark
 * @param  Instance the device instance
 * @param  Watermark FIFO data level threshold
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Set_Watermark_Level(uint32_t Instance, uint8_t Watermark)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set the stop on watermark function
 * @param  Instance the device instance
 * @param  Stop the state of stop on watermark function
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Stop_On_Watermark(uint32_t Instance, uint8_t Stop)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Enable FIFO usage
 * @param  Instance the device instance
 * @param  Status the pointer to the status
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_FIFO_Usage(uint32_t Instance, uint8_t Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set the high temperature threshold value
 * @param  Instance the device instance
 * @param  Value the high temperature threshold to be set
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Set_High_Temperature_Threshold(uint32_t Instance, float Value)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set the low temperature threshold value
 * @param  Instance the device instance
 * @param  Value the low temperature threshold to be set
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Set_Low_Temperature_Threshold(uint32_t Instance, float Value)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get temperature limit status
 * @param  Instance the device instance
 * @param  HighLimit indicates that high temperature limit has been exceeded
 * @param  LowLimit indicates that low temperature limit has been exceeded
 * @param  ThermLimit indicates that therm temperature limit has been exceeded
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Get_Temperature_Limit_Status(uint32_t Instance, uint8_t *HighLimit, uint8_t *LowLimit, uint8_t *ThermLimit)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Enable or disable interrupt on EVENT pin
 * @param  Instance the device instance
 * @param  Enable 0 disable the EVENT pin, 1 enable EVENT pin
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Set_Event_Pin(uint32_t Instance, uint8_t Enable)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      ret = BSP_ERROR_COMPONENT_FAILURE;
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Set environmental sensor one shot mode
 * @param  Instance environmental sensor instance to be used
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Set_One_Shot(uint32_t Instance)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      if (HTS221_Set_One_Shot(EnvCompObj[Instance]) != BSP_ERROR_NONE)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
      else
      {
        ret = BSP_ERROR_NONE;
      }
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/**
 * @brief  Get environmental sensor one shot status
 * @param  Instance environmental sensor instance to be used
 * @param  Status pointer to the one shot status (1 means measurements available, 0 means measurements not available yet)
 * @retval BSP status
 */
int32_t CUSTOM_ENV_SENSOR_Get_One_Shot_Status(uint32_t Instance, uint8_t *Status)
{
  int32_t ret;

  switch (Instance)
  {
#if (USE_CUSTOM_ENV_SENSOR_HTS221_0 == 1)
    case CUSTOM_HTS221_0:
      if (HTS221_Get_One_Shot_Status(EnvCompObj[Instance], Status) != BSP_ERROR_NONE)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
      else
      {
        ret = BSP_ERROR_NONE;
      }
      break;
#endif

    default:
      ret = BSP_ERROR_WRONG_PARAM;
      break;
  }

  return ret;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
