/**
 * @file js_modules.h
 * Rough copy of applications/system/js_app/js_modules.h
 * 
 * Only kept the necessary parts for compatibility with the plugin system and mjs imports.
 */

#pragma once

#include <core/common_defines.h>

#include <flipper_application/flipper_application.h>
#include <flipper_application/plugins/plugin_manager.h>
#include <flipper_application/plugins/composite_resolver.h>

#include <furi.h>
#include <mjs_core_public.h>
#include <mjs_ffi_public.h>
#include <mjs_exec_public.h>
#include <mjs_object_public.h>
#include <mjs_string_public.h>
#include <mjs_array_public.h>
#include <mjs_util_public.h>
#include <mjs_primitive_public.h>
#include <mjs_array_buf_public.h>

#define INST_PROP_NAME "_"

#define PLUGIN_APP_ID      "js"
#define PLUGIN_API_VERSION 1

typedef void* (*JsModeConstructor)(struct mjs* mjs, mjs_val_t* object);
typedef void (*JsModeDestructor)(void* inst);

typedef struct {
    char* name;
    JsModeConstructor create;
    JsModeDestructor destroy;
} JsModuleDescriptor;
