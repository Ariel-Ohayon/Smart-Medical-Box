#ifndef LCD_I2C_H
#define LCD_I2C_H

void lcd_cmd(char val);
void lcd_data(char val);
void lcd_print(char STR[16]);
void lcd_init();
void lcd_clear();
void lcd_setCursor(int line,int Cursor);
void lcd_create_char(uint8_t address, uint8_t *pixels);

#endif
