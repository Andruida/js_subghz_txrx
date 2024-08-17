#include "js_subghz_txrx.h"

void js_subghz_txrx_get_preset(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 0)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    SubGhzRadioPreset preset = subghz_txrx_get_preset(instance);

    mjs_val_t ret = mjs_mk_object(mjs);
    mjs_set(mjs, ret, "name", ~0, mjs_mk_string(mjs, furi_string_get_cstr(preset.name), ~0, true));
    mjs_set(mjs, ret, "frequency", ~0, mjs_mk_number(mjs, preset.frequency));
    mjs_set(mjs, ret, "data", ~0, mjs_mk_array_buf(mjs, (char*)preset.data, preset.data_size));

    mjs_return(mjs, ret);
}
