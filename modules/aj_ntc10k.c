// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_ntc10k.h"

static const uint32_t ntc10k_table[] ={
    133500UL, 125672UL, 118350UL, 111498UL, 105084UL,   // -25^C to -21^C
    99073UL,  93469UL,  88175UL,  83230UL,  78591UL,    // -20^C to -16^C
    74238UL,  70153UL,  66316UL,  62712UL,  59325UL,    // -15^C to -11^C
    56142UL,  53148UL,  50331UL,  47680UL,  45184UL,    // -10^C to -6^C
    42834UL,  40620UL,  38533UL,  36566UL,  34710UL,    // -5^C to -1^C
    32960UL,  31308UL,  29749UL,  28276UL,  26885UL,    // 0^C to 4^C
    25570UL,  24327UL,  23153UL,  22041UL,  20989UL,    // 5^C to 9^C
    19993UL,  19051UL,  18158UL,  17312UL,  16511UL,    // 10^C to 14^C
    15751UL,  15031UL,  14347UL,  13699UL,  13083UL,    // 15^C to 19^C
    12499UL,  11944UL,  11417UL,  10916UL,  10440UL,    // 20^C to 24^C
    10000UL,  9557UL,   9147UL,   8758UL,   8387UL,     // 25^C to 29^C
    8033UL,   7698UL,   7377UL,   7072UL,   6781UL,     // 30^C to 34^C
    6504UL,   6239UL,   5987UL,   5746UL,   5517UL,     // 35^C to 39^C
    5298UL,   5088UL,   4888UL,   4697UL,   4515UL,     // 40^C to 44^C
    4347UL,   4173UL,   4015UL,   3862UL,   3716UL,     // 45^C to 49^C
    3588UL,   3443UL,   3315UL,   3193UL,   3076UL,     // 50^C to 54^C
    2963UL,   2856UL,   2753UL,   2654UL,   2559UL,     // 55^C to 59^C
    2468UL,   2381UL,   2297UL,   2217UL,   2140UL,     // 60^C to 64^C
    2066UL,   1995UL,   1927UL,   1861UL,   1798UL,     // 65^C to 69^C
    1738UL,   1680UL,   1623UL,   1570UL,   1518UL,     // 70^C to 74^C
    1473UL,   1420UL,   1375UL,   1330UL,   1287UL,     // 75^C to 79^C
    1246UL,   1207UL,   1169UL,   1132UL,   1097UL,     // 80^C to 84^C
    1062UL,   1030UL,   998UL,    967UL,    938UL,      // 85^C to 89^C
    910UL,    882UL,    856UL,    830UL,    806UL,      // 90^C to 94^C
    782UL,    759UL,    737UL,    715UL,    695UL,      // 95^C to 99^C
    674UL,    655UL,    637UL,    620UL,    601UL,      // 100^C to 104^C
    584UL,    568UL,    552UL,    537UL,    522UL,      // 105^C to 109^C
    508UL,    494UL,    480UL,    467UL,    455UL,      // 110^C to 114^C
    443UL,    431UL,    419UL,    408UL,    398UL,      // 115^C to 119^C
    388UL,    377UL,    367UL,    358UL,    349UL,      // 120^C to 124^C
    340UL                                               // 125^C
};

#define NTC10K_TABLE_SIZE (sizeof(ntc10k_table) / sizeof(ntc10k_table[0]))

static uint16_t ntc_last_index = 75;

//********************************************
int16_t AJ_NTC10K_ConvertOhmToTemp_LastIndex(uint32_t ohm){
    uint16_t i = ntc_last_index;

    if (ohm >= ntc10k_table[0]){
        return AJ_NTC10K_TEMP_MIN;
    }

    if (ohm <= ntc10k_table[NTC10K_TABLE_SIZE - 1]){
        return AJ_NTC10K_TEMP_MAX;
    }

    if (ohm < ntc10k_table[i]){
        while (i < (NTC10K_TABLE_SIZE - 1) && ohm < ntc10k_table[i]){
            i++;
        }
    }
    else{
        while (i > 0 && ohm > ntc10k_table[i-1]){
            i--;
        }
    }

    ntc_last_index = i;

    return (int16_t)((i-1) - 25);
}

//********************************************
int16_t AJ_NTC10K_ConvertOhmToTemp(uint32_t ohm){
    uint16_t low  = 0;
    uint16_t high = NTC10K_TABLE_SIZE - 1;
    uint16_t mid = 0;

    if (ohm >= ntc10k_table[0]){
        return AJ_NTC10K_TEMP_MIN;
    }

    if (ohm <= ntc10k_table[high]){
        return AJ_NTC10K_TEMP_MAX;
    }

    /* Binary search */
    while (low < high){
        mid = (low + high + 1) >> 1;

        if (ohm > ntc10k_table[mid]){
            high = mid - 1;
        }
        else{
            low = mid;
        }
    }

    return (int16_t)(low - 25);
}

//********************************************
//int16_t AJ_NTC10K_ConvertOhmToTemp(uint32_t ohm){
//    uint16_t low = 0;
//    uint16_t high = NTC10K_TABLE_SIZE - 1;
//    uint16_t mid = 0;
//
//    if (ohm >= ntc10k_table[0]){
//        return -25;
//    }
//
//    if (ohm <= ntc10k_table[NTC10K_TABLE_SIZE - 1]){
//        return 125;
//    }
//
//    while (low <= high){
//        mid = (low + high) >> 1;
//
//        if (ntc10k_table[mid] == ohm){
//            return (int16_t)(mid - 25);
//        }
//
//        if (ntc10k_table[mid] > ohm){
//            low = mid + 1;
//        }
//        else{
//            high = mid - 1;
//        }
//    }
//
//    return (int16_t)(low - 25);
//}