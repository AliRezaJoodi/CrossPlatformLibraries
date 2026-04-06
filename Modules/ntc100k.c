// GitHub Account: GitHub.com/AliRezaJoodi

#include "ntc100k.h"

const uint32_t ntc100k_table5c[] = {
    10723236UL, // -55°C
    7366689UL,  // -50°C
    5132757UL,  // -45°C
    3624165UL,  // -40°C
    2591304UL,  // -35°C
    1874913UL,  // -30°C
    1371886UL,  // -25°C
    1014545UL,  // -20°C
    757881UL,   // -15°C
    571590UL,   // -10°C
    435026UL,   // -5°C
    333964UL,   // 0°C
    258497UL,   // 5°C
    201659UL,   // 10°C
    158499UL,   // 15°C
    125468UL,   // 20°C
    100000UL,   // 25°C
    80223UL,    // 30°C
    64759UL,    // 35°C
    52589UL,    // 40°C
    42951UL,    // 45°C
    35272UL,    // 50°C
    29119UL,    // 55°C
    24161UL,    // 60°C
    20144UL,    // 65°C
    16874UL,    // 70°C
    14198UL,    // 75°C
    11998UL,    // 80°C
    10181UL,    // 85°C
    8674UL,     // 90°C
    7419UL,     // 95°C
    6369UL,     // 100°C
    5487UL,     // 105°C
    4744UL,     // 110°C
    4115UL,     // 115°C
    3581UL,     // 120°C
    3126UL,     // 125°C
    2737UL,     // 130°C
    2404UL,     // 135°C
    2117UL,     // 140°C
    1869UL,     // 145°C
    1655UL,     // 150°C
    1469UL,     // 155°C
    1307UL,     // 160°C
    1166UL,     // 165°C
    1043UL,     // 170°C
    935UL,      // 175°C
    839UL,      // 180°C
    755UL,      // 185°C
    681UL,      // 190°C
    616UL,      // 195°C
    558UL,      // 200°C
    506UL,      // 205°C
    460UL,      // 210°C
    419UL,      // 215°C
    382UL,      // 220°C
    349UL,      // 225°C
    320UL,      // 230°C
    293UL,      // 235°C
    269UL,      // 240°C
    247UL,      // 245°C
    228UL,      // 250°C
    210UL,      // 255°C
    194UL,      // 260°C
    179UL,      // 265°C
    166UL,      // 270°C
    154UL,      // 275°C
    143UL,      // 280°C
    133UL,      // 285°C
    124UL,      // 290°C
    116UL,      // 295°C
    108UL       // 300°C
};

#define NTC100K_TABLE_SIZE (sizeof(ntc100k_table5c) / sizeof(ntc100k_table5c[0]))

int16_t NTC100K_ConvertOhmToTemp(uint32_t ohm){
    uint8_t i;
    uint32_t r1, r2;
    int16_t t;

    if(ohm >= ntc100k_table5c[0]){
        return -55;
    }

    if(ohm <= ntc100k_table5c[NTC100K_TABLE_SIZE-1]){
        return 300;
    }

    for(i = 0; i < (NTC100K_TABLE_SIZE - 1); i++){
        r1 = ntc100k_table5c[i];
        r2 = ntc100k_table5c[i+1];

        if(ohm <= r1 && ohm >= r2){
            t = (int16_t)((i * 5) - 55);
            t += (int16_t)((5 * (r1 - ohm)) / (r1 - r2));
            return t;
        }
    }

    return -100;
}