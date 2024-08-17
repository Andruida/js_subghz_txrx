#include "js_subghz_txrx.h"

void js_subghz_txrx_get_preset_name(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 1)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    mjs_val_t preset_arg = mjs_arg(mjs, 0);
    if(!mjs_is_string(preset_arg)) {
        JS_THROW_BAD_TYPE("preset must be string type");
    }
    const char* preset = mjs_get_cstring(mjs, &preset_arg);

    const char* preset_name = subghz_txrx_get_preset_name(instance, preset);

    mjs_return(mjs, mjs_mk_string(mjs, preset_name, ~0, true));
}
