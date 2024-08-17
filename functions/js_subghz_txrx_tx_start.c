#include "js_subghz_txrx.h"

#define HAS_STRING(obj, key)                                                             \
    do {                                                                                 \
        if(!mjs_is_string(mjs_get(mjs, obj, key, ~0))) {                                 \
            JS_THROW_BAD_ARGS(#obj "." key " has to be defined and has to be a string"); \
        }                                                                                \
    } while(0);

void js_subghz_txrx_tx_start(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 1)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    mjs_val_t data = mjs_arg(mjs, 0);
    if(!mjs_is_object(data)) {
        JS_THROW_BAD_TYPE("data must be an object");
    }
    HAS_STRING(data, "Filetype");
    if(!mjs_is_number(mjs_get(mjs, data, "Version", ~0))) {
        JS_THROW_BAD_ARGS("data.Version has to be defined and has to be a number (usually 1)");
    }
    HAS_STRING(data, "Frequency");
    HAS_STRING(data, "Protocol");
    HAS_STRING(data, "Preset");

    mjs_val_t filetype_val = mjs_get(mjs, data, "Filetype", ~0);
    const char* filetype = mjs_get_cstring(mjs, &filetype_val);
    if(filetype == NULL) {
        JS_THROW_BAD_ARGS("Filetype is not defined");
    }
    mjs_val_t version_val = mjs_get(mjs, data, "Version", ~0);
    int version = mjs_get_int(mjs, version_val);
    if(version == 0) {
        JS_THROW_BAD_ARGS("Version cannot be 0");
    }

    FlipperFormat* flipper_format = flipper_format_string_alloc();
    flipper_format_write_header_cstr(flipper_format, filetype, version);
    mjs_val_t key, iter = MJS_UNDEFINED;
    while((key = mjs_next(mjs, data, &iter)) != MJS_UNDEFINED) {
        if(!mjs_is_string(key)) {
            JS_THROW_BAD_ARGS("Keys must be strings");
        }

        const char* key_str = mjs_get_cstring(mjs, &key);
        if(strcmp(key_str, "Filetype") == 0 || strcmp(key_str, "Version") == 0) {
            continue;
        }
        mjs_val_t val = mjs_get_v(mjs, data, key);
        if(mjs_is_string(val)) {
            const char* val_str = mjs_get_cstring(mjs, &val);
            flipper_format_write_string_cstr(flipper_format, key_str, val_str);
        } else if(mjs_is_number(val)) {
            int32_t val_int = mjs_get_int(mjs, val);
            flipper_format_write_int32(flipper_format, key_str, &val_int, 1);
        } else if(mjs_is_array(val)) {
        } else if(mjs_is_array_buf(val)) {
            size_t len;
            uint8_t* buf = (uint8_t*)mjs_array_buf_get_ptr(mjs, val, &len);
            flipper_format_write_hex(flipper_format, key_str, buf, len);
        } else if(mjs_is_typed_array(val) && mjs_is_data_view(val)) {
            mjs_val_t buf = mjs_dataview_get_buf(mjs, val);
            size_t len;
            uint8_t* buf_ptr = (uint8_t*)mjs_array_buf_get_ptr(mjs, buf, &len);
            flipper_format_write_hex(flipper_format, key_str, buf_ptr, len);
        } else {
            JS_THROW_BAD_ARGS("Values must be strings, numbers, or byte-arrays");
        }
    }

    SubGhzTxRxStartTxState result = subghz_txrx_tx_start(instance, flipper_format);

    flipper_format_free(flipper_format); // Is this ok?

    mjs_return(mjs, mjs_mk_number(mjs, (double)result));
}
