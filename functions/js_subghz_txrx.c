#include "js_subghz_txrx.h"

#define REGISTER_FUNC(name) JS_FIELD(#name, MJS_MK_FN(js_subghz_txrx_##name));

static void* js_subghz_txrx_create(struct mjs* mjs, mjs_val_t* object, JsModules* modules) {
    // UNUSED(object);
    // UNUSED(mjs);
    UNUSED(modules);
    JsSubghzTxRxInst* js_subghz_txrx = malloc(sizeof(JsSubghzTxRxInst));
    mjs_val_t andruida_subghz_obj = mjs_mk_object(mjs);

    js_subghz_txrx->counter = 0;
    js_subghz_txrx->txrx = subghz_txrx_alloc();

    mjs_set(mjs, andruida_subghz_obj, INST_PROP_NAME, ~0, mjs_mk_foreign(mjs, js_subghz_txrx));
    JS_ASSIGN_MULTI(mjs, andruida_subghz_obj) {
        REGISTER_FUNC(add);
        REGISTER_FUNC(get);
        REGISTER_FUNC(alloc);
        REGISTER_FUNC(free);
        REGISTER_FUNC(is_database_loaded);
        REGISTER_FUNC(load_decoder_by_name_protocol);
        REGISTER_FUNC(set_preset);
        REGISTER_FUNC(get_preset_name);
        REGISTER_FUNC(get_preset);
        REGISTER_FUNC(get_frequency_and_modulation);
        REGISTER_FUNC(tx_start);
        REGISTER_FUNC(rx_start);
        REGISTER_FUNC(stop);
        REGISTER_FUNC(sleep);
        REGISTER_FUNC(hopper_update);
        REGISTER_FUNC(hopper_get_state);
        REGISTER_FUNC(hopper_set_state);
        REGISTER_FUNC(hopper_unpause);
        REGISTER_FUNC(hopper_pause);
        REGISTER_FUNC(speaker_on);
        REGISTER_FUNC(speaker_off);
        REGISTER_FUNC(speaker_mute);
        REGISTER_FUNC(speaker_unmute);
        REGISTER_FUNC(speaker_get_state);
        REGISTER_FUNC(speaker_set_state);
    }

    *object = andruida_subghz_obj;

    return js_subghz_txrx;
}

static void js_subghz_txrx_destroy(void* inst) {
    JsSubghzTxRxInst* js_subghz_txrx = inst;

    if(js_subghz_txrx->txrx != NULL) {
        subghz_txrx_free(js_subghz_txrx->txrx);
    }
    if(js_subghz_txrx->preset_name != NULL) {
        free((void*)js_subghz_txrx->preset_name);
    }
    if(js_subghz_txrx->preset_data != NULL) {
        free((void*)js_subghz_txrx->preset_data);
    }

    free(js_subghz_txrx);
}

static const JsModuleDescriptor js_subghz_txrx_desc = {
    "subghz_txrx",
    js_subghz_txrx_create,
    js_subghz_txrx_destroy,
    NULL,
};

static const FlipperAppPluginDescriptor plugin_descriptor = {
    .appid = PLUGIN_APP_ID,
    .ep_api_version = PLUGIN_API_VERSION,
    .entry_point = &js_subghz_txrx_desc,
};

const FlipperAppPluginDescriptor* js_subghz_txrx_ep(void) {
    return &plugin_descriptor;
}
