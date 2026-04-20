#ifndef SHT1X_CONFIG_INCLUDED
#define SHT1X_CONFIG_INCLUDED

//typedef enum{
//    SHT1X_VDD_2V5 = 2500U,
//    SHT1X_VDD_3V  = 3000U,
//    SHT1X_VDD_3V5 = 3500U,
//    SHT1X_VDD_4V  = 4000U,
//    SHT1X_VDD_5V  = 5000U
//
//} SHT1x_Vdd_t;

#define SHT1X_VDD_2V5   2500U
#define SHT1X_VDD_3V    3000U
#define SHT1X_VDD_3V5   3500U
#define SHT1X_VDD_4V    4000U
#define SHT1X_VDD_5V    5000U

#ifndef SHT1X_CONFIG
#define SHT1X_CONFIG
    #define SHT1X_VDD               SHT1X_VDD_5V

    #warning "SHT1X_CONFIG is not defined; default configuration will be used."
#endif

//#if (SHT1X_VDD != SHT1X_VDD_5V)  && \
//    (SHT1X_VDD != SHT1X_VDD_4V)  && \
//    (SHT1X_VDD != SHT1X_VDD_3V5) && \
//    (SHT1X_VDD != SHT1X_VDD_3V)  && \
//    (SHT1X_VDD != SHT1X_VDD_2V5)
//
//    #error "Invalid SHT1X_VDD selection!"
//#endif

#endif
