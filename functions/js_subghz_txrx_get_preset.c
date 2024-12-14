#include "js_subghz_txrx.h"

void js_subghz_txrx_get_preset(struct mjs* mjs) {
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY); // 0 args
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    SubGhzRadioPreset preset = subghz_txrx_get_preset(instance);

    mjs_val_t ret = mjs_mk_object(mjs);
    JS_ASSIGN_MULTI(mjs, ret) {
        JS_FIELD("name", mjs_mk_string(mjs, furi_string_get_cstr(preset.name), ~0, true));
        JS_FIELD("frequency", mjs_mk_number(mjs, preset.frequency));
        JS_FIELD("data", mjs_mk_array_buf(mjs, (char*)preset.data, preset.data_size));
    }

    mjs_return(mjs, ret);
}
