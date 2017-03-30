/**
 * @file lv_style.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#include "lv_style.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_style_t lv_style_def;
static lv_style_t lv_style_weak;
static lv_style_t lv_style_scr;
//static lv_style_t lv_style_transp;         /*Transparent container*/
//static lv_style_t lv_style_plain;          /*Plain container*/
static lv_style_t lv_style_light;          /*Light colored container*/
static lv_style_t lv_style_dark;           /*Dark colored container*/
static lv_style_t lv_style_paper;          /*White paper-like container*/
static lv_style_t lv_style_btn_rel;
static lv_style_t lv_style_btn_pr;
static lv_style_t lv_style_btn_trel;
static lv_style_t lv_style_btn_tpr;
static lv_style_t lv_style_btn_ina;
//static lv_style_t lv_style_label;          /*Raw label style*/
//static lv_style_t lv_style_img;            /*Raw image style*/
//static lv_style_t lv_style_line;           /*Raw line style*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 *  Init the basic styles
 */
void lv_style_init (void)
{
    /*Default style (set every attribute!)*/
    lv_style_set_ccolor(&lv_style_def, COLOR_MAKE(0x30, 0xF0, 0x30));
    lv_style_set_opa(&lv_style_def, OPA_COVER);
    lv_style_set_opa_prop(&lv_style_def, true);

    lv_style_set_mcolor(&lv_style_def, COLOR_SILVER);
    lv_style_set_gcolor(&lv_style_def, COLOR_SILVER);
    lv_style_set_bcolor(&lv_style_def, COLOR_BLACK);
    lv_style_set_lcolor(&lv_style_def, COLOR_GRAY);
    lv_style_set_radius(&lv_style_def, 0);
    lv_style_set_bwidth(&lv_style_def, 2);
    lv_style_set_lwidth(&lv_style_def, 0);
    lv_style_set_vpad(&lv_style_def, LV_DPI / 4);
    lv_style_set_hpad(&lv_style_def, LV_DPI / 4);
    lv_style_set_opad(&lv_style_def, LV_DPI / 4);
    lv_style_set_bopa(&lv_style_def, OPA_COVER);
    lv_style_set_empty(&lv_style_def, false);

    lv_style_set_font(&lv_style_def, font_get(LV_FONT_DEFAULT));
    lv_style_set_letter_space(&lv_style_def, 10 * LV_DOWNSCALE);
    lv_style_set_line_space(&lv_style_def, 1 * LV_DOWNSCALE);
    lv_style_set_txt_align(&lv_style_def, 0);

    lv_style_set_img_recolor(&lv_style_def, OPA_TRANSP);

    lv_style_set_line_width(&lv_style_def, 1 * LV_DOWNSCALE);


    /*Weak style (inherit everything)*/
    memcpy(&lv_style_weak, &lv_style_def, sizeof(lv_style_t));
    memset(&lv_style_weak.set, 0, sizeof(lv_style_weak.set));   /*Make all attributes cleared*/

    /*Screen style*/
    memcpy(&lv_style_scr, &lv_style_def, sizeof(lv_style_t));

    /*Light style*/
    memcpy(&lv_style_light, &lv_style_weak, sizeof(lv_style_t));
    lv_style_set_ccolor(&lv_style_light, COLOR_MAKE(0x30, 0x30, 0x30));
    lv_style_set_opa(&lv_style_light, OPA_COVER);
    lv_style_set_opa_prop(&lv_style_light, true);

    lv_style_set_mcolor(&lv_style_light, COLOR_SILVER);
    lv_style_set_gcolor(&lv_style_light, COLOR_GRAY);
    lv_style_set_bcolor(&lv_style_light, COLOR_WHITE);
    lv_style_set_lcolor(&lv_style_light, COLOR_BLACK);
    lv_style_set_radius(&lv_style_light, LV_DPI / 10);
    lv_style_set_bwidth(&lv_style_light, LV_DPI / 30 >= 1 ? LV_DPI / 30 >= 1 : 1);
    lv_style_set_lwidth(&lv_style_light, LV_DPI / 4);
    lv_style_set_vpad(&lv_style_light, LV_DPI / 4);
    lv_style_set_hpad(&lv_style_light, LV_DPI / 4);
    lv_style_set_opad(&lv_style_light, LV_DPI / 4);
    lv_style_set_bopa(&lv_style_light, OPA_50);
    lv_style_set_empty(&lv_style_light, false);

    lv_style_set_img_recolor(&lv_style_light, OPA_TRANSP);

    lv_style_set_line_width(&lv_style_light, LV_DPI / 30 >= 1 ? LV_DPI / 30 >= 1 : 1);

    /*Dark style*/
    memcpy(&lv_style_dark, &lv_style_light, sizeof(lv_style_t));
    lv_style_set_ccolor(&lv_style_dark, COLOR_MAKE(0xd0, 0xd0, 0xd0));
    lv_style_set_mcolor(&lv_style_dark, COLOR_GRAY);
    lv_style_set_gcolor(&lv_style_dark, COLOR_BLACK);
    lv_style_set_bcolor(&lv_style_dark, COLOR_WHITE);
    lv_style_set_lwidth(&lv_style_dark, 10);

    /*Paper style*/
    memcpy(&lv_style_paper, &lv_style_light, sizeof(lv_style_t));
    lv_style_set_ccolor(&lv_style_paper, COLOR_MAKE(0x30, 0x30, 0x30));
    lv_style_set_mcolor(&lv_style_paper, COLOR_WHITE);
    lv_style_set_gcolor(&lv_style_paper, COLOR_WHITE);
    lv_style_set_bcolor(&lv_style_paper, COLOR_GRAY);
    lv_style_set_lwidth(&lv_style_paper, 0);


    /*Button released style*/
    memcpy(&lv_style_btn_rel, &lv_style_weak, sizeof(lv_style_t));
    lv_style_set_mcolor(&lv_style_btn_rel, COLOR_WHITE);
    lv_style_set_gcolor(&lv_style_btn_rel, COLOR_GRAY);

    /*Button pressed style*/
    memcpy(&lv_style_btn_pr, &lv_style_btn_rel, sizeof(lv_style_t));
    lv_style_set_mcolor(&lv_style_btn_pr, COLOR_BLACK);
    lv_style_set_ccolor(&lv_style_btn_pr, COLOR_SILVER);
    lv_style_set_lcolor(&lv_style_btn_pr, COLOR_GRAY);
    lv_style_set_lwidth(&lv_style_btn_pr, 10);

    /*Button toggle released style*/
    memcpy(&lv_style_btn_trel, &lv_style_btn_rel, sizeof(lv_style_t));
    lv_style_set_mcolor(&lv_style_btn_trel, COLOR_LIME);

    /*Button toggle pressed style*/
    memcpy(&lv_style_btn_tpr, &lv_style_btn_rel, sizeof(lv_style_t));
    lv_style_set_mcolor(&lv_style_btn_tpr, COLOR_GREEN);

    /*Button inactive style*/
    memcpy(&lv_style_btn_ina, &lv_style_btn_rel, sizeof(lv_style_t));
    lv_style_set_mcolor(&lv_style_btn_ina, COLOR_YELLOW);
}


/**
 * Get style from its name
 * @param style_name an element of the 'lv_style_name_t' enum
 * @return pointer to the requested style (lv_style_def by default)
 */
lv_style_t * lv_style_get(lv_style_name_t style_name)
{
    lv_style_t * style = &lv_style_def;

    switch(style_name) {
        case LV_STYLE_DEF:
            style = &lv_style_def;
            break;
        case LV_STYLE_WEAK:
            style = &lv_style_weak;
            break;
        case LV_STYLE_SCR:
            style =  &lv_style_scr;
            break;
        case LV_STYLE_LIGHT:
            style =  &lv_style_light;
            break;
        case LV_STYLE_DARK:
            style =  &lv_style_dark;
            break;
        case LV_STYLE_PAPER:
            style =  &lv_style_paper;
            break;
        case LV_STYLE_BTN_REL:
            style =  &lv_style_btn_rel;
            break;
        case LV_STYLE_BTN_PR:
            style =  &lv_style_btn_pr;
            break;
        case LV_STYLE_BTN_TREL:
            style =  &lv_style_btn_trel;
            break;
        case LV_STYLE_BTN_TPR:
            style =  &lv_style_btn_tpr;
            break;
        case LV_STYLE_BTN_INA:
            style =  &lv_style_btn_ina;
            break;
        default:
            style =  &lv_style_def;
    }

    return style;
}
#include <stdio.h>
/**
 * Inherit all not set attributes of child style from a parent style
 * @param result pointer to a 'lv_style_t' variable to store the result style
 * @param child pointer to a child style. (if NULL 'lv_style_def' will be used)
 * @param parent pointer to a parent style (if NULL 'lv_style_def' will be used)
 */
lv_style_t * lv_style_inherit(lv_style_t * result, const lv_style_t * child, const lv_style_t * parent )
{

    /*If the two styles are the same do nothing*/
    static uint32_t cnt = 0;

    cnt++;
    printf("Style inherit: %d\n", cnt);

    /*If both styles are specified make the inheritance*/
    memcpy(result, child, sizeof(lv_style_t));

    if(child == parent) return result;

    /*If an attribute of a child is not set then inherit is from the parent*/
    if(child->set._ccolor == 0) result->ccolor.full = parent->ccolor.full;
    if(child->set._opa == 0) result->opa = parent->opa;

    if(child->set._mcolor == 0) result->mcolor.full = parent->mcolor.full;
    if(child->set._gcolor == 0) result->gcolor.full = parent->gcolor.full;
    if(child->set._bcolor == 0) result->bcolor.full = parent->bcolor.full;
    if(child->set._lcolor == 0) result->lcolor.full = parent->lcolor.full;
    if(child->set._radius == 0) result->radius = parent->radius;
    if(child->set._lwidth == 0) result->lwidth = parent->lwidth;
    if(child->set._bwidth == 0) result->bwidth = parent->bwidth;
    if(child->set._vpad == 0) result->vpad = parent->vpad;
    if(child->set._hpad == 0) result->hpad = parent->hpad;
    if(child->set._opad == 0) result->opad = parent->opad;
    if(child->set._empty == 0) result->empty = parent->empty;

    if(child->set._font == 0) result->font = parent->font;
    if(child->set._letter_space == 0) result->letter_space = parent->letter_space;
    if(child->set._line_space == 0) result->line_space = parent->line_space;

    if(child->set._img_recolor == 0) result->img_recolor = parent->img_recolor;

    if(child->set._line_width == 0) result->line_width = parent->line_width;

    return result;
}

/**
 * Set the content color of a style
 * @param style pointer to style
 * @param ccolor content color
 */
void lv_style_set_ccolor(lv_style_t * style, color_t ccolor)
{
    style->ccolor = ccolor;
    style->set._ccolor = 1;
}

/**
 * Clear the content color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_ccolor(lv_style_t * style)
{
    style->set._ccolor = 0;
}

/**
 * Set the opacity of a style
 * @param style pointer to style
 * @param opa opacity (OPA_COVER, OPA_TRANSP, OPA_10, OPA_20 ... OPA_90)
 */
void lv_style_set_opa(lv_style_t * style, opa_t opa)
{
    style->opa = opa;
    style->set._opa = 1;
}

/**
 * Clear the opacity of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opa(lv_style_t * style)
{
    style->set._opa = 0;
}

/**
 * Set the proportional opacity attribute of a style (make the opacity relative to the parent)
 * @param style pointer to style
 * @param opa_prop true: enabled, false: disabled
 */
void lv_style_set_opa_prop(lv_style_t * style, bool opa_prop)
{
    style->opa_prop = opa_prop == false ? 0 : 1;
    style->set._opa_prop = 1;
}

/**
 * Clear the proportional opacity attribute of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opa_prop(lv_style_t * style)
{
    style->set._opa_prop = 0;
}


/**
 * Set the container main color of a style
 * @param style pointer to style
 * @param mcolor main color of the background
 */
void lv_style_set_mcolor(lv_style_t * style, color_t mcolor)
{
    style->mcolor = mcolor;
    style->set._mcolor = 1;
}

/**
 * Clear the container main color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_mcolor(lv_style_t * style)
{
    style->set._mcolor = 0;
}

/**
 * Set the container gradient color of a style
 * @param style pointer to style
 * @param gcolor gradient color of the background
 */
void lv_style_set_gcolor(lv_style_t * style, color_t gcolor)
{
    style->gcolor = gcolor;
    style->set._gcolor = 1;
}

/**
 * Clear the container gradient color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_gcolor(lv_style_t * style)
{
    style->set._gcolor = 0;
}

/**
 * Set the container border color of a style
 * @param style pointer to style
 * @param bcolor border color of the background
 */
void lv_style_set_bcolor(lv_style_t * style, color_t bcolor)
{
    style->bcolor = bcolor;
    style->set._bcolor = 1;
}

/**
 * Clear the container border color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bcolor(lv_style_t * style)
{
    style->set._bcolor = 0;
}

/**
 * Set the container light (shadow effect) color of a style
 * @param style pointer to style
 * @param lcolor light (shadow) color of the background
 */
void lv_style_set_lcolor(lv_style_t * style, color_t lcolor)
{
    style->lcolor = lcolor;
    style->set._lcolor = 1;
}

/**
 * Clear the container light color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_lcolor(lv_style_t * style)
{
    style->set._lcolor = 0;
}

/**
 * Set the container corner radius of a style
 * @param style pointer to style
 * @param radius corner radius of the background (>= 0)
 */
void lv_style_set_radius(lv_style_t * style, cord_t radius)
{
    style->radius = radius;
    style->set._radius = 1;
}

/**
 * Clear the container radius of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_radius(lv_style_t * style)
{
    style->set._radius = 0;
}

/**
 * Set the container border width of a style
 * @param style pointer to style
 * @param bwidth border width of the background (>= 0, 0 means no border)
 */
void lv_style_set_bwidth(lv_style_t * style, cord_t bwidth)
{
    style->bwidth = bwidth;
    style->set._bwidth = 1;
}


/**
 * Clear the container border width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bwidth(lv_style_t * style)
{
    style->set._bwidth = 0;
}

/**
 * Set the container light (shadow) width of a style
 * @param style pointer to style
 * @param lwidth light (shadow) width of the background (>= 0, 0 means no shadow)
 */
void lv_style_set_lwidth(lv_style_t * style, cord_t lwidth)
{
    style->lwidth = lwidth;
    style->set._lwidth = 1;
}

/**
 * Clear the container light (shadow) width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_lwidth(lv_style_t * style)
{
    style->set._lwidth = 0;
}

/**
 * Set the container vertical padding of a style
 * @param style pointer to style
 * @param vpad vertical padding on the background
 */
void lv_style_set_vpad(lv_style_t * style, cord_t vpad)
{
    style->vpad = vpad;
    style->set._vpad = 1;
}

/**
 * Clear the container vertical padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_vpad(lv_style_t * style)
{
    style->set._vpad = 0;
}

/**
 * Set the container horizontal padding of a style
 * @param style pointer to style
 * @param hpad horizontal padding on the background
 */
void lv_style_set_hpad(lv_style_t * style, cord_t hpad)
{
    style->hpad = hpad;
    style->set._hpad = 1;
}

/**
 * Clear the container horizontal padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_hpad(lv_style_t * style)
{
    style->set._hpad = 0;
}

/**
 * Set the container object padding of a style
 * @param style pointer to style
 * @param opad padding between objects on the background
 */
void lv_style_set_opad(lv_style_t * style, cord_t opad)
{
    style->opad = opad;
    style->set._opad = 1;
}

/**
 * Clear the container object padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opad(lv_style_t * style)
{
    style->set._opad = 0;
}

/**
 * Set the container border opacity of a style (relative to the object opacity)
 * @param style pointer to style
 * @param bopa border opacity of the background  (OPA_COVER, OPA_TRANSP, OPA_10, OPA_20 ... OPA_90)
 */
void lv_style_set_bopa(lv_style_t * style, opa_t bopa)
{
    style->bopa = bopa;
    style->set._bopa = 1;
}

/**
 * Clear the container border opacity of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bopa(lv_style_t * style)
{
    style->set._bopa = 0;
}

/**
 * Set container empty attribute of a style (transparent background but border drawn)
 * @param style pointer to style
 * @param empty true: empty enable, false: empty disable
 */
void lv_style_set_empty(lv_style_t * style, bool empty)
{
    style->empty = empty == false ? 0 : 1;
    style->set._empty = 1;
}

/**
 * Clear the container empty attribute of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_empty(lv_style_t * style)
{
    style->set._empty = 0;
}

/**
 * Set the font of a style
 * @param style pointer to style
 * @param font pointer to a fint
 */
void lv_style_set_font(lv_style_t * style, const font_t * font)
{
    style->font = font;
    style->set._font = 1;
}

/**
 * Clear the font of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_font(lv_style_t * style)
{
    style->set._font = 0;
}

/**
 * Set the letter space of a style
 * @param style pointer to style
 * @param letter_space new letter space
 */
void lv_style_set_letter_space(lv_style_t * style, cord_t letter_space)
{
    style->letter_space = letter_space;
    style->set._letter_space = 1;
}

/**
 * Clear the letter space of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_letter_space(lv_style_t * style)
{
    style->set._letter_space = 0;
}

/**
 * Set the line space of a style
 * @param style pointer to style
 * @param line_space new letter space
 */
void lv_style_set_line_space(lv_style_t * style, cord_t line_space)
{
    style->line_space = line_space;
    style->set._line_space = 1;
}

/**
 * Clear the line space of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_line_space(lv_style_t * style)
{
    style->set._line_space = 0;
}

/**
 * Set the text align of a style
 * @param style pointer to style
 * @param align TODO
 */
void lv_style_set_txt_align(lv_style_t * style, uint8_t align)
{
    style->txt_align = align;
    style->set._txt_align = 1;
}

/**
 * Clear the text align of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_txt_align(lv_style_t * style)
{
    style->set._txt_align = 0;
}

/**
 * Set the image re-color intensity of a style
 * @param style pointer to style
 * @param recolor re-coloring intensity (OPA_TRANSP: do nothing, OPA_COVER: fully re-color, OPA_10: little re-color)
 */
void lv_style_set_img_recolor(lv_style_t * style, opa_t recolor)
{
    style->img_recolor = recolor;
    style->set._img_recolor = 1;
}

/**
 * Clear the image recolor of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_img_recolor(lv_style_t * style)
{
    style->set._img_recolor = 0;
}

/**
 * Set the line width of a style
 * @param style pointer to style
 * @param width new line width (>=0)
 */
void lv_style_set_line_width(lv_style_t * style, cord_t width)
{
    style->line_width = width;
    style->set._line_width = 1;
}

/**
 * Clear the line width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_line_width(lv_style_t * style)
{
    style->set._line_width = 0;
}


/**********************
 *   STATIC FUNCTIONS
 **********************/
