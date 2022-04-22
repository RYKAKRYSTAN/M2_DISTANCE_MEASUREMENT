#include"unity.h"
extern void  LCD_Char (char char_data);
extern void LCD_Clear(void);
extern void LCD_Command(char cmd);
extern void LCD_Init(void);
extern void LCD_String_xy (char row, char pos, char *str);
extern void LCD_String (char *str);

void setUp(void)
{

}
void tearDown(void)
{

}
int main(void)
{
    UnityBegin(NULL);
    RUN_TEST( LCD_Char);
    RUN_TEST( LCD_Clear );
    RUN_TEST(LCD_Command);
    RUN_TEST( LCD_Init);
    RUN_TEST(LCD_String_xy);
    RUN_TEST(LCD_String);
    
    return(UnityEnd());

}
