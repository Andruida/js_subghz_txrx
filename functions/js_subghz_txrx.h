#pragma once

#include "js_subghz_txrx_i.h"
#include <applications/system/js_app/js_modules.h>
#include "../lib/subghz_txrx_i.h"
#include "../lib/util.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TAG "js_subghz_txrx"

#define JS_THROW(err) JS_ERROR_AND_RETURN(mjs, MJS_INTERNAL_ERROR, err)

#define JS_THROW_BAD_ARGS(err) JS_ERROR_AND_RETURN(mjs, MJS_BAD_ARGS_ERROR, err)

#define JS_THROW_BAD_TYPE(err) JS_ERROR_AND_RETURN(mjs, MJS_BAD_ARGS_ERROR, err)

void js_subghz_txrx_add(struct mjs* mjs);

void js_subghz_txrx_get(struct mjs* mjs);

void js_subghz_txrx_alloc(struct mjs* mjs);

void js_subghz_txrx_free(struct mjs* mjs);

void js_subghz_txrx_is_database_loaded(struct mjs* mjs);

void js_subghz_txrx_load_decoder_by_name_protocol(struct mjs* mjs);

void js_subghz_txrx_set_preset(struct mjs* mjs);

void js_subghz_txrx_get_preset_name(struct mjs* mjs);

void js_subghz_txrx_get_preset(struct mjs* mjs);

void js_subghz_txrx_get_frequency_and_modulation(struct mjs* mjs);

void js_subghz_txrx_tx_start(struct mjs* mjs);

void js_subghz_txrx_rx_start(struct mjs* mjs);

void js_subghz_txrx_stop(struct mjs* mjs);

void js_subghz_txrx_sleep(struct mjs* mjs);

void js_subghz_txrx_hopper_update(struct mjs* mjs);

void js_subghz_txrx_hopper_get_state(struct mjs* mjs);

void js_subghz_txrx_hopper_set_state(struct mjs* mjs);

void js_subghz_txrx_hopper_unpause(struct mjs* mjs);

void js_subghz_txrx_hopper_pause(struct mjs* mjs);

void js_subghz_txrx_speaker_on(struct mjs* mjs);

void js_subghz_txrx_speaker_off(struct mjs* mjs);

void js_subghz_txrx_speaker_mute(struct mjs* mjs);

void js_subghz_txrx_speaker_unmute(struct mjs* mjs);

void js_subghz_txrx_speaker_get_state(struct mjs* mjs);

void js_subghz_txrx_speaker_set_state(struct mjs* mjs);

const FlipperAppPluginDescriptor* js_subghz_txrx_ep(void);
