#pragma once

#include "../lv_conf.h"
#include "../lv_drv_conf.h"
#include "../lvgl/lvgl.h"

bool LVGLSwiftDriverInit(uint32_t width, uint32_t height);
const lv_font_t *LVGLSwiftDefaultFontWithSize(uint32_t size);

lv_coord_t LVGLSwiftCoordMin();
lv_coord_t LVGLSwiftCoordMax();
lv_coord_t LVGLSwiftSizeContent();
