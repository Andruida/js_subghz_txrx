#include "js_subghz_txrx.h"

void js_subghz_txrx_free(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 0)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    subghz_txrx_free(js_subghz_txrx->txrx);
    js_subghz_txrx->txrx = NULL;

    if(js_subghz_txrx->preset_name != NULL) {
        free((void*)js_subghz_txrx->preset_name);
        js_subghz_txrx->preset_name = NULL;
    }
    if(js_subghz_txrx->preset_data != NULL) {
        free((void*)js_subghz_txrx->preset_data);
        js_subghz_txrx->preset_data = NULL;
        js_subghz_txrx->preset_data_len = 0;
    }

    mjs_return(mjs, MJS_UNDEFINED);
}