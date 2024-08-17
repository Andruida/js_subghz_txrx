#include "js_subghz_txrx.h"

void js_subghz_txrx_get_frequency_and_modulation(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 1)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    mjs_val_t long_name_arg = mjs_arg(mjs, 0);
    if(!mjs_is_boolean(long_name_arg)) {
        JS_THROW_BAD_TYPE("long_name must be boolean type");
    }
    bool long_name = mjs_get_bool(mjs, long_name_arg);

    mjs_val_t ret = mjs_mk_object(mjs);

    FuriString* frequency = furi_string_alloc();
    FuriString* modulation = furi_string_alloc();
    subghz_txrx_get_frequency_and_modulation(instance, frequency, modulation, long_name);

    mjs_set(
        mjs, ret, "frequency", ~0, mjs_mk_string(mjs, furi_string_get_cstr(frequency), ~0, true));
    mjs_set(
        mjs, ret, "modulation", ~0, mjs_mk_string(mjs, furi_string_get_cstr(modulation), ~0, true));

    furi_string_free(frequency);
    furi_string_free(modulation);

    mjs_return(mjs, ret);
}
