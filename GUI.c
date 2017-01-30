/*
 * GUI.c
 *
 *  Created on: ٢٨‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */

#include "EEPROM.h"
#include "TbUart.h"
#include "AnalogDigital.h"
#include "lcdEKE.h"

int main(void){
//local data types for TB
U8_t inf=0,ad=0x01;
U8_t TEMP=0;

struct ANALOG setting={'A',1,1,1,64,0};

//System initialization for GUI
 EEPROM_init();
 TbUart_init();
 ADC_init_EKE(setting);
 EKE_LCD_INIT();

	while(1){

//	x=TbUart_get_char();

	//GET temperature value
    TEMP=((ADC_Read()*5)/10);
    //Store data in EEPROM
    EEPROM_Write((U8_t)ad,(U8_t)TEMP);
    inf=EEPROM_Read((U8_t)ad,(U8_t)1);
    //TB display
    TbUart_Send_stri((U8_t*)"Temperature is : ");
    TB_intNumASCII(inf);
    TbUart_Send_char('\n');

    //LCD display
    goToRowColumn(1,1);
    EKE_LCD_string((U8_t*)"Temperature is : ");
    goToRowColumn(2,8);
    EKE_LCD_intNumASCII((U8_t)inf);


	}

	return 0;
}
