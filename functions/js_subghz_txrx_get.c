#include "js_subghz_txrx.h"

void js_subghz_txrx_get(struct mjs* mjs) {
    JsSubghzTxRxInst* js_subghz_txrx = JS_GET_CONTEXT(mjs);
    furi_check(js_subghz_txrx);

    // FURI_LOG_I(TAG, "js_subghz_txrx_get current: %d", js_subghz_txrx->counter);

    mjs_val_t obj = mjs_struct_to_obj(
        mjs,
        js_subghz_txrx,
        (struct mjs_c_struct_member[]){
            {"counter", offsetof(JsSubghzTxRxInst, counter), MJS_STRUCT_FIELD_TYPE_INT, NULL},
            {NULL, 0, 0, NULL}, // VERY IMPORTANT
        });

    mjs_return(mjs, obj);
}