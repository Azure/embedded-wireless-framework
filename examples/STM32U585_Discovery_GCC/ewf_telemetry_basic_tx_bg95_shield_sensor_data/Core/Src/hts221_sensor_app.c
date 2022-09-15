// Reference: https://www.st.com/resource/en/design_tip/dm00777536-how-to-import-stmemsstandardcdrivers-in-an-stm32cubeide-project.pdf
#include "hts221.h"
#include "custom_env_sensors.h"

float linear_interpolation(lin_t *lin, int16_t x)
{
	return ((lin->y1 - lin->y0) * x + ((lin->x1 * lin->y0) - (lin->x0 * lin->y1))) / (lin->x1 - lin->x0);
}

static uint8_t whoamI;
lin_t lin_hum;
lin_t lin_temp;
stmdev_ctx_t hts221Driver;

HAL_StatusTypeDef Init_HTS221(void);

static int32_t hts221_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
static int32_t hts221_write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);

typedef union {
	int16_t i16bit;
	uint8_t u8bit[2];
} axis1bit16_t;
typedef union {
	int32_t i32bit;
	uint8_t u8bit[4];
} axis1bit32_t;
typedef union {
	int16_t i16bit[3];
	uint8_t u8bit[6];
} axis3bit16_t;

hts221_reg_t reg_HTS221;
static axis1bit16_t data_raw_humidity_HTS221;
static axis1bit16_t data_raw_temperature_HTS221;

HAL_StatusTypeDef hts_221_sensor_init(void);
HAL_StatusTypeDef hts_221_sensor_read(float * humidity_perc_HTS221, float * temperature_degC_HTS221);

HAL_StatusTypeDef hts_221_sensor_init()
{
	hts221Driver.handle = &hi2c2;
	hts221Driver.read_reg = hts221_read;
	hts221Driver.write_reg = hts221_write;
	/* Check device ID for Humidity sensor */
	whoamI = 0;
	hts221_device_id_get(&hts221Driver, &whoamI);
	/* Configure Humidity sensor */
	if (whoamI == HTS221_ID)
	{
		/* Enable Block Data Update */
		hts221_block_data_update_set(&hts221Driver, PROPERTY_ENABLE);
		/* Set Output Data Rate */
		hts221_data_rate_set(&hts221Driver, HTS221_ODR_12Hz5);
		hts221_humidity_avg_set(&hts221Driver, HTS221_H_AVG_4);
		hts221_temperature_avg_set(&hts221Driver, HTS221_T_AVG_2);
		/* Device Power On */
		hts221_power_on_set(&hts221Driver, PROPERTY_ENABLE);
		/* Read humidity calibration coefficient */
		hts221_hum_adc_point_0_get(&hts221Driver, &lin_hum.x0);
		hts221_hum_rh_point_0_get(&hts221Driver, &lin_hum.y0);
		hts221_hum_adc_point_1_get(&hts221Driver, &lin_hum.x1);
		hts221_hum_rh_point_1_get(&hts221Driver, &lin_hum.y1);
		/* Read temperature calibration coefficient */
		hts221_temp_adc_point_0_get(&hts221Driver, &lin_temp.x0);
		hts221_temp_deg_point_0_get(&hts221Driver, &lin_temp.y0);
		hts221_temp_adc_point_1_get(&hts221Driver, &lin_temp.x1);
		hts221_temp_deg_point_1_get(&hts221Driver, &lin_temp.y1);
		return HAL_OK;
	}
	else
	{
		return HAL_ERROR;
	}
}

HAL_StatusTypeDef hts_221_sensor_read(float * humidity_perc_HTS221_ptr, float * temperature_degC_HTS221_ptr)
{
	/* Humidity from HTS221 */
	hts221_status_get(&hts221Driver, &reg_HTS221.status_reg);
	if (reg_HTS221.status_reg.h_da)
	{
		memset(&data_raw_humidity_HTS221.i16bit, 0x00, sizeof(int16_t));
		hts221_humidity_raw_get(&hts221Driver, &data_raw_humidity_HTS221.i16bit);
		*humidity_perc_HTS221_ptr = linear_interpolation(&lin_hum, data_raw_humidity_HTS221.i16bit);
		if (*humidity_perc_HTS221_ptr < 0) *humidity_perc_HTS221_ptr = 0;
		if (*humidity_perc_HTS221_ptr > 100) *humidity_perc_HTS221_ptr = 100;
	}
	/* Temperature from HTS221 */
	if (reg_HTS221.status_reg.t_da)
	{
		memset(&data_raw_temperature_HTS221.i16bit, 0x00, sizeof(int16_t));
		hts221_temperature_raw_get(&hts221Driver, &data_raw_temperature_HTS221.i16bit);
		*temperature_degC_HTS221_ptr = linear_interpolation(&lin_temp, data_raw_temperature_HTS221.i16bit);
	}
	return HAL_OK;

}

static int32_t hts221_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len) {
	if (len > 1) reg |= 0x80;
	return HAL_I2C_Mem_Read(handle, HTS221_I2C_ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
}

static int32_t hts221_write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len) {
	if (len > 1) reg |= 0x80;
	return HAL_I2C_Mem_Write(handle, HTS221_I2C_ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
}
