/***************************************************************************
 * Lab07.c (barebones starter code version)
 *
 *   Created: 10/13/2026
 *    Author: James Myhill
 * Processor: ATmega128A (on a ReadyAVR)
 *
 * Your comments go here...
 *
 **************************************************************************/

/* your #include file declaration(s) go here */
#include "UARTLibrary.h"

/* your #define declarations go here */
#define BaudRate 9600
#define DataBits 8
#define StopBits 1
#define NoParity 0

// prototype subroutine definitions
void initializeArray(unsigned char *cp);
void displayArray(unsigned char *cp);
void updateArray(unsigned char *cp);

int main(void)
{
	// create a 61-char array


	// Initialize the UART
	// ProfNote:  Understand the UARTLibary.h before blindly running the next line!
	//uart_init(BaudRate, DataBits, StopBits, NoParity);
	
	// ProfNote:  Initial Testing Only!  Comment out after UART confirmed working!
//	while (1) {
//		uart_tx('H');uart_tx('e');uart_tx('l');uart_tx('l');uart_tx('o');uart_tx('\r');uart_tx('\n');
//		uart_tx('W');uart_tx('o');uart_tx('r');uart_tx('l');uart_tx('d');uart_tx('!');uart_tx('\r');uart_tx('\n');
//	}
	
    /* your code goes here */
	
	unsigned char array[61];
	initializeArray(array);
	uart_init(BaudRate, DataBits, StopBits, NoParity);
	for(int i =0; i < 122; i++){
		displayArray(array);
		updateArray(array);
	}

}

/* your subroutines go here */
void initializeArray(unsigned char *cp){
	unsigned char i = 0;
	while(i < 61){
		if(i == 30){
		*(cp + i) = '*';
	}else{
		*(cp + i) = ' ';
	}
	i++;
}
	
}
void displayArray(unsigned char *cp){
	// ProfNote:  Look through your line using "uart_tx(<char>)" to print one character at a time.
	// At the end of the line, use "uart_tx('\r'); uart_tx('\n');" to print a new line to keep your
	// output aligned properly.
	for(int i = 0; i < 61;i++){
		uart_tx(*(cp + i));
	}
	uart_tx('\r'); uart_tx('\n');
	
}
void updateArray(unsigned char *cp){
	unsigned char next[61];
	next[0] = ' ';
	next[60] = ' ';
	for(int i = 1;i < 60;i++){
		unsigned char left = *(cp + i - 1);
		unsigned char center = *(cp + i);
		unsigned char right = *(cp + i + 1);
		
		if(left == ' ' && center == ' ' && right == '*'){
			next[i] = '*';
		}else if(left == ' ' && center == '*' && right == '*'){
			next[i] = '*';
		}else if(left == '*' && center == ' ' && right == ' '){
			next[i] = '*';
		}else{
			next[i] = ' ';
		}
		
	}
	memcpy(cp,next,61);
}