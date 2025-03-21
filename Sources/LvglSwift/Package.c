#include <stdlib.h>
#include <unistd.h>

#include "Package.h"

#if USE_SDL_GPU
#include "sdl/sdl_gpu.h"
#else
#include "sdl/sdl.h"
#endif

static lv_disp_t *display;
static lv_disp_draw_buf_t drawBuffer;
static lv_indev_drv_t inputDrv;
static lv_disp_drv_t displayDrv;
static lv_color_t *frameBuffer;

bool LVGLSwiftDriverInit(uint32_t width, uint32_t height)
{
    free(frameBuffer);
    frameBuffer = (lv_color_t *)calloc(width * height, sizeof(lv_color_t));
    if (frameBuffer == NULL)
        return false;

    sdl_init();

    lv_disp_draw_buf_init(&drawBuffer, frameBuffer, NULL, width * height);
    lv_disp_drv_init(&displayDrv);
    displayDrv.draw_buf = &drawBuffer;
    displayDrv.hor_res = width;
    displayDrv.ver_res = height;
    displayDrv.flush_cb = sdl_display_flush;
#if USE_SDL_GPU
    sdl_disp_drv_init(&displayDrv, displayDrv.hor_res, displayDrv.ver_res);
#endif
    display = lv_disp_drv_register(&displayDrv);
    
    lv_indev_drv_init(&inputDrv);
    inputDrv.type = LV_INDEV_TYPE_POINTER;
    
    inputDrv.read_cb = sdl_mouse_read;
    lv_indev_drv_register(&inputDrv);

    return true;
}

const lv_font_t *LVGLSwiftDefaultFontWithSize(uint32_t size)
{
    switch (size) {
#define LV_FONT_WITH_SIZE(x)    case (x): return &lv_font_montserrat_##x
            
#if LV_FONT_MONTSERRAT_8
            LV_FONT_WITH_SIZE(8);
#endif
#if LV_FONT_MONTSERRAT_12
            LV_FONT_WITH_SIZE(12);
#endif
#if LV_FONT_MONTSERRAT_14
            LV_FONT_WITH_SIZE(14);
#endif
#if LV_FONT_MONTSERRAT_16
            LV_FONT_WITH_SIZE(16);
#endif
#if LV_FONT_MONTSERRAT_18
            LV_FONT_WITH_SIZE(18);
#endif
#if LV_FONT_MONTSERRAT_20
            LV_FONT_WITH_SIZE(20);
#endif
#if LV_FONT_MONTSERRAT_22
            LV_FONT_WITH_SIZE(22);
#endif
#if LV_FONT_MONTSERRAT_24
            LV_FONT_WITH_SIZE(24);
#endif
#if LV_FONT_MONTSERRAT_26
            LV_FONT_WITH_SIZE(26);
#endif
#if LV_FONT_MONTSERRAT_28
            LV_FONT_WITH_SIZE(28);
#endif
#if LV_FONT_MONTSERRAT_30
            LV_FONT_WITH_SIZE(30);
#endif
#if LV_FONT_MONTSERRAT_32
            LV_FONT_WITH_SIZE(32);
#endif
#if LV_FONT_MONTSERRAT_34
            LV_FONT_WITH_SIZE(34);
#endif
#if LV_FONT_MONTSERRAT_36
            LV_FONT_WITH_SIZE(36);
#endif
#if LV_FONT_MONTSERRAT_38
            LV_FONT_WITH_SIZE(38);
#endif
#if LV_FONT_MONTSERRAT_40
            LV_FONT_WITH_SIZE(40);
#endif
#if LV_FONT_MONTSERRAT_42
            LV_FONT_WITH_SIZE(42);
#endif
#if LV_FONT_MONTSERRAT_44
            LV_FONT_WITH_SIZE(44);
#endif
#if LV_FONT_MONTSERRAT_46
            LV_FONT_WITH_SIZE(46);
#endif
#if LV_FONT_MONTSERRAT_48
            LV_FONT_WITH_SIZE(48);
#endif
        default:
            return NULL;
    }
}

lv_coord_t LVGLSwiftCoordMin(void)
{
    return LV_COORD_MIN;
}

lv_coord_t LVGLSwiftCoordMax(void)
{
    return LV_COORD_MAX;
}

lv_coord_t LVGLSwiftSizeContent(void)
{
    return LV_SIZE_CONTENT;
}
