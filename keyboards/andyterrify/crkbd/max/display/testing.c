#include "testing.h"
#include "qp.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
// #include "gfx/mb.qgf.h"
#include "qp_lvgl.h"
#include "printf.h"
#include "transactions.h"
#include "screens.h"
#include "styles.h"
// #include "gfx/ezgif.h"

painter_device_t lcd;
bool    master;
lv_obj_t *label;

LV_FONT_DECLARE(pixellari_18);

// void screen_sync_slave_handler(uint8_t length, const void *in_data, uint8_t out_buflen, void *out_data) {
//     uint8_t *data = (uint8_t *)in_data;
//     // processes_command(data, length);
// }


void display_init(void) {
    master = is_keyboard_master();
    uprintf("Post Init\n");
    wait_ms(LCD_WAIT_TIME);
    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, LCD_SPI_MODE);
    qp_init(lcd, LCD_ROTATION);

    // Apply Offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    if (qp_lvgl_attach(lcd)) {     // Attach LVGL to the display
        // label = lv_label_create(lv_scr_act());
        // lv_label_set_text(label, "Hello World");
        // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0); // Center the label}
    }
}

uint8_t currScreen   = 0xFF;
int     currlay      = 0;
int     lastlay      = 0xFF;

void display_housekeeping_task(void) {
    // Update the layer button matrix to show selected layer
    currlay = get_highest_layer(layer_state);
    switch (currlay) {
        case 0:
            lv_label_set_text(label, "Base");
            break;
        case 1:
            lv_label_set_text(label, "Raise");
            break;
        case 2:
            lv_label_set_text(label, "Lower");
            break;
        case 3:
            lv_label_set_text(label, "Adjust");
            break;
        case 4:
            lv_label_set_text(label, "Game");
            break;
        case 5:
            lv_label_set_text(label, "Game");
            break;
        default:
            lv_label_set_text(label, "Unknown");
            break;
    }
}

void suspend_power_down_user(void) {
    qp_power(lcd, false);
}

void suspend_wakeup_init_user(void) {
    qp_power(lcd, true);
}
