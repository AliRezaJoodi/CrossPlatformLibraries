// Editing…

#ifndef SHT1X_INCLUDED
#define SHT1X_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "sht1x_config.h"
#include "sht1x_port.h"

#define CMD_MEASURE_TEMPERATURE     0x03U
#define CMD_MEASURE_HUMIDITY        0x05U
#define CMD_SOFT_RESET              0x1EU

#define SHT1X_ERROR_ACK     0U
#define SHT1X_ERROR_CRC     1U

//typedef enum {
//    SHT1X_SCALE_1       = 0,   /**< 2^0 */
//    SHT1X_SCALE_2       = 1,   /**< 2^1 */
//    SHT1X_SCALE_4       = 2,   /**< 2^2 */
//    SHT1X_SCALE_8       = 3,   /**< 2^3 */
//    SHT1X_SCALE_16      = 4,   /**< 2^4 */
//    SHT1X_SCALE_32      = 5,   /**< 2^5 */
//    SHT1X_SCALE_64      = 6,   /**< 2^6 */
//    SHT1X_SCALE_128     = 7,   /**< 2^7 */
//    SHT1X_SCALE_256     = 8,   /**< 2^8 */
//    SHT1X_SCALE_512     = 9,   /**< 2^9 */
//    SHT1X_SCALE_1024    = 10,  /**< 2^10 */
//    SHT1X_SCALE_2048    = 11,  /**< 2^11 */
//    SHT1X_SCALE_4096    = 12,  /**< 2^12 */
//    SHT1X_SCALE_8192    = 13,  /**< 2^13 */
//    SHT1X_SCALE_16384   = 14,  /**< 2^14 */
//    SHT1X_SCALE_32768   = 15,  /**< 2^15 */
//    SHT1X_SCALE_65536   = 16,  /**< 2^16 */
//    SHT1X_SCALE_131072  = 17   /**< 2^17 */
//} SHT1X_Scale_t;
//
//#define SHT1X_SCALE_TEMPERATURE         SHT1X_SCALE_128
//#define SHT1X_FLOAT_TO_Q(x, scale)      ((int32_t)((x) * (float)(1UL << (scale)) + 0.5f))

void SHT1x_Init(SHT1x_t *sht);
void SHT1x_ResetConnection(SHT1x_t *sht);
void SHT1x_SoftReset(SHT1x_t *sht);

uint8_t SHT1x_StartMeasurement(SHT1x_t *sht, uint8_t command);
uint16_t ReadSO(SHT1x_t *sht, uint8_t command);

uint16_t SHT1x_GetTemperature(SHT1x_t *sht);
float SHT1x_GetTemperature_(SHT1x_t *sht);
float Get_Humidity(SHT1x_t *sht);

#ifdef __cplusplus
}
#endif

#endif

