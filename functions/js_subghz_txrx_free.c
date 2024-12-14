#include "js_subghz_txrx.h"

void js_subghz_txrx_free(struct mjs* mjs) {
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY); // 0 args
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

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