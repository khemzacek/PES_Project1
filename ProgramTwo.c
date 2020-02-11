/* PES Project One Program Two */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	unsigned int x;
	char type[18] = "ERROR";
	const char* wsCharCodes[] = 
						{"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB",
						"LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3",
						"DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS",
						"RS", "US", "SPACE"
						};
	
	
	// Check for valid number of inputs
	if(argc != 2){
		printf("ERROR: Invalid number of inputs\n");
		return 1;
	}
	
	
	// Get input code as number
	sscanf(argv[1], "%u", &x);
	// Check input value
	if(!(x < 127)){
		printf("ERROR: Please input value 0-127");
		return 0;
	}
	
	
	// Check if white space char
	if((x <= 32) || (x == 127)){
		strncpy(type, "White Space", 18);
		printf("Code: %u\t Type: %s\t ASCII Char: %s\n", x, type, wsCharCodes[x]);
		return 0;
	}
	
	
	// Check all other types
	if((x >= 48) && (x <= 57)){
		strncpy(type, "Digit", 18);
	}else if((x >= 65) && (x <= 90)){
		strncpy(type, "Upper Case", 18);
	}else if((x >= 97) && (x <= 122)){
		strncpy(type, "Lower Case", 18);
	}else{
		strncpy(type, "Special Character", 18);
	}
	
	printf("Code: %u\t Type: %s\t ASCII Char: %c\n", x, type, x);
	
	return 0;
}