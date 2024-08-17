#pragma once

#include "../lib/subghz_txrx_i.h"
#include <stdint.h>

typedef struct JsSubghzTxRxInst {
    int counter;
    SubGhzTxRx* txrx;
    const char* preset_name;
    const uint8_t* preset_data;
    size_t preset_data_len;
} JsSubghzTxRxInst;