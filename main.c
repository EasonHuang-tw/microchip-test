/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/
int flag = 0;
int UART1_prescaler = 1000;
void UART1_WriteS(char *s, int size);
int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        while(flag == 0);
        UART1_WriteS("A",1);
        flag = 0;
        //for(int i =0;i<10000;i++) Nop();
        Nop();
    }    
}
void UART1_WriteS(char *s, int size){
    for(int i = 0; i < size; i++) {
		UART1_Write(s[i]);
	}
}
void TMR1_TimeoutCallback( void ){
    Nop();
    UART1_prescaler--;
    if(UART1_prescaler == 0){
        flag = 1;
        UART1_prescaler = 50; //TMR1:1000Hz UART1_prescaler:1000 -> 20Hz
    }
}