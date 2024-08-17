#include "js_subghz_txrx.h"

void js_subghz_txrx_set_preset(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 3)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    mjs_val_t preset_name_arg = mjs_arg(mjs, 0);
    if(!mjs_is_string(preset_name_arg)) {
        JS_THROW_BAD_TYPE("preset_name must be a string");
    }
    const char* preset_name = mjs_get_cstring(mjs, &preset_name_arg);
    size_t preset_name_len = strlen(preset_name);
    if(preset_name_len == 0) {
        JS_THROW_BAD_ARGS("preset_name must not be empty");
    }
    char* preset_name_local = malloc(preset_name_len + 1);
    if(preset_name_local == NULL) {
        JS_THROW("out of memory");
    }
    memcpy(preset_name_local, preset_name, preset_name_len);
    preset_name_local[preset_name_len] = '\0';
    js_subghz_txrx->preset_name = preset_name_local;

    mjs_val_t frequency_arg = mjs_arg(mjs, 1);
    if(!mjs_is_number(frequency_arg)) {
        JS_THROW_BAD_TYPE("frequency must be a number");
    }
    uint32_t frequency = mjs_get_int32(mjs, frequency_arg);
    if(frequency <= 1'000'000 || frequency >= 1'000'000'000) {
        JS_THROW_BAD_ARGS(
            "frequency must be between 1MHz and 1GHz (1'000'000Hz and 1'000'000'000Hz)");
    }

    mjs_val_t preset_data_arg = mjs_arg(mjs, 2);

    if(mjs_is_typed_array(preset_data_arg) && mjs_is_data_view(preset_data_arg)) {
        preset_data_arg = mjs_dataview_get_buf(mjs, preset_data_arg);
    }
    if(!mjs_is_array_buf(preset_data_arg)) {
        JS_THROW_BAD_TYPE("preset_data must be an array buffer or dataview (Uint8Array)");
    }
    size_t preset_data_len;
    uint8_t* preset_data = (uint8_t*)mjs_array_buf_get_ptr(mjs, preset_data_arg, &preset_data_len);
    uint8_t* preset_data_local = malloc(preset_data_len);
    if(preset_data_local == NULL) {
        JS_THROW("out of memory");
    }
    memcpy(preset_data_local, preset_data, preset_data_len);
    js_subghz_txrx->preset_data = preset_data_local;
    js_subghz_txrx->preset_data_len = preset_data_len;

    subghz_txrx_set_preset(
        instance, preset_name_local, frequency, preset_data_local, preset_data_len);

    mjs_return(mjs, MJS_UNDEFINED);
}
