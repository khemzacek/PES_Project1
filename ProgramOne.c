/* PES Project One Program One */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare max/min (for given operand size) globally
// define for 16 bits, can easily be shifted for 4/8 bits
int maxUnsign = 0xFFFF;
int minUnsign = 0x0000;
int maxSign = 0x7FFF;	//max is same bit sequence/value for all representations
						//ones comp and sign mag are neg versions of max
int minTwos = 0x8000;
const char errMsg[6] = {"ERROR"};


char* binaryStr(int x, int numBits)
{	
	static char bitStr[20];
	bitStr[0] = '0';
	bitStr[1] = 'b';
	
	for(int i = 1; i<=numBits; i++){
		if(((x>>(numBits-i)) & 0x1) == 1){
			bitStr[i+1] = '1';
		}else{
			bitStr[i+1] = '0';
		}
	}
	
	bitStr[numBits+2] = '\0';
	return bitStr;
}


int signMag(int x, int opSize)
{
	int bitMask = 1;
	
	if(x < 0){
		bitMask = bitMask<<(opSize-1);
		x = abs(x)|bitMask;
	}
	
	return x;
}


void outAllErrs(void)
{
	// Print table
	printf("Output:\t\t\t Value             \t Maximum           \t Minimum\n");
	printf("Binary (abs)\t\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Octal (abs)\t\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Decimal (abs)\t\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Hexadecimal (abs)\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Signed One's Complement\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Signed Two's Complement\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	printf("Sign-Magnitude\t\t %-18s\t %-18s\t %-18s\n", errMsg, errMsg, errMsg);
	
	return;
}


void outValueErrs(int opSize)
{
	// Variables to hold max strings for all binary representations
		// prevents multiple calls of binaryStr within single printf statement, preventing overwrite
	char maxString[18];
	
	// Print table
	printf("Output:\t\t\t Value             \t Maximum           \t Minimum\n");
	strncpy(maxString, binaryStr(maxUnsign, opSize), 18);
	printf("Binary (abs)\t\t %-18s\t %-18s\t %-18s\n", errMsg,
														maxString,
														binaryStr(minUnsign, opSize));
	printf("Octal (abs)\t\t %-18s\t %-#18o\t %-#18o\n", errMsg, maxUnsign, minUnsign);
	printf("Decimal (abs)\t\t %-18s\t %-18d\t %-18d\n", errMsg, maxUnsign, minUnsign);
	printf("Hexadecimal (abs)\t %-18s\t %-#18X\t %-#18X\n", errMsg, maxUnsign, minUnsign);
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	printf("Signed One's Complement\t %-18s\t %-18s\t %-18s\n", errMsg,
																maxString,
																binaryStr(~maxSign, opSize));
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	printf("Signed Two's Complement\t %-18s\t %-18s\t %-18s\n", errMsg,
																maxString,
																binaryStr(minTwos, opSize));
	strncpy(maxString, binaryStr(signMag(maxSign, opSize), opSize), 18);
	printf("Sign-Magnitude\t\t %-18s\t %-18s\t %-18s\n", errMsg,
														maxString,
														binaryStr(signMag(maxSign, opSize), opSize));
	
	return;
}


void outSignedErrs(int value, int opSize, short valid2s)
{
	// Variables to hold min/max strings for all binary representations
		// prevents multiple calls of binaryStr within single printf statement, preventing overwrite
	char maxString[18];
	char minString[18];
	
	// Print table
	printf("Output:\t\t\t Value             \t Maximum           \t Minimum\n");
	strncpy(maxString, binaryStr(maxUnsign, opSize), 18);
	strncpy(minString, binaryStr(minUnsign, opSize), 18);
	printf("Binary (abs)\t\t %-18s\t %-18s\t %-18s\n", binaryStr(abs(value), opSize),
														maxString,
														minString);
	printf("Octal (abs)\t\t %-#18o\t %-#18o\t %-#18o\n", abs(value), maxUnsign, minUnsign);
	printf("Decimal (abs)\t\t %-18d\t %-18d\t %-18d\n", abs(value), maxUnsign, minUnsign);
	printf("Hexadecimal (abs)\t %-#18X\t %-#18X\t %-#18X\n", abs(value), maxUnsign, minUnsign);
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	strncpy(minString, binaryStr(~maxSign, opSize), 18);
	printf("Signed One's Complement\t %-18s\t %-18s\t %-18s\n", errMsg,
																maxString,
																minString);
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	strncpy(minString, binaryStr(minTwos, opSize), 18);
	printf("Signed Two's Complement\t %-18s\t %-18s\t %-18s\n", 
											((valid2s == 1)?binaryStr((~abs(value))+1, opSize):errMsg),
											maxString,
											minString);
	strncpy(maxString, binaryStr(signMag(maxSign, opSize), opSize), 18);
	strncpy(minString, binaryStr(signMag((-1*maxSign), opSize), opSize), 18);
	printf("Sign-Magnitude\t\t %-18s\t %-18s\t %-18s\n", errMsg,
														maxString,
														minString);
	
	return;
}


void outFullTable(int value, int opSize)
{
	// Variables to hold min/max strings for all binary representations
		// prevents multiple calls of binaryStr within single printf statement, preventing overwrite
	char maxString[18];
	char minString[18];
	
	// Print table
	printf("Output:\t\t\t Value             \t Maximum           \t Minimum\n");
	strncpy(maxString, binaryStr(maxUnsign, opSize), 18);
	strncpy(minString, binaryStr(minUnsign, opSize), 18);
	printf("Binary (abs)\t\t %-18s\t %-18s\t %-18s\n", binaryStr(abs(value), opSize),
														maxString,
														minString);
	printf("Octal (abs)\t\t %-#18o\t %-#18o\t %-#18o\n", abs(value), maxUnsign, minUnsign);
	printf("Decimal (abs)\t\t %-18d\t %-18d\t %-18d\n", abs(value), maxUnsign, minUnsign);
	printf("Hexadecimal (abs)\t %-#18X\t %-#18X\t %-#18X\n", abs(value), maxUnsign, minUnsign);
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	strncpy(minString, binaryStr(~maxSign, opSize), 18);
	printf("Signed One's Complement\t %-18s\t %-18s\t %-18s\n", 
										(value<0)?binaryStr(~abs(value), opSize):binaryStr(value, opSize),
										maxString,
										minString);
	strncpy(maxString, binaryStr(maxSign, opSize), 18);
	strncpy(minString, binaryStr(minTwos, opSize), 18);
	printf("Signed Two's Complement\t %-18s\t %-18s\t %-18s\n", binaryStr(value, opSize),
																maxString,
																minString);
	strncpy(maxString, binaryStr(signMag(maxSign, opSize), opSize), 18);
	strncpy(minString, binaryStr(signMag((-1*maxSign), opSize), opSize), 18);
	printf("Sign-Magnitude\t\t %-18s\t %-18s\t %-18s\n",
													binaryStr(signMag(value, opSize), opSize),
													maxString,
													minString);
	
	return;
}


int main(int argc, char* argv[])
{
	// Input variables initialized to values that will never be valid
	// in case value cannot be obtained using sscanf on inputs
	int value = 2147483647;
	int radix = 0;
	int opSize = 0;
	/*int maxUnsign, minUnsign;
	int maxOnes, minOnes, valueOnes;
	int maxTwos, minTwos, valueTwos;
	int maxSM, minSM, valueSM;
	*/
	
	// Check for valid number of inputs
	if(argc != 4){
		printf("ERROR: Invalid number of inputs\n");
		return 1;
	}
	
	
	// Print inputs line
	printf("Input: Value %-7s  Radix %-7s  Operand Size %-7s\n", argv[1], argv[2], argv[3]);
	
	
	// Get operand size, check if valid
	sscanf(argv[3], "%d", &opSize);
	if((opSize != 4)&&(opSize != 8)&&(opSize != 16)){
		printf("ERROR: Invalid operand size\n");
		outAllErrs();
		return 0;
	}
	
	
	// Set min/max for opSize
	maxUnsign = maxUnsign>>(16-opSize);
	minUnsign = minUnsign>>(16-opSize);
	maxSign = maxSign>>(16-opSize);
	minTwos = minTwos>>(16-opSize);
	
	
	// Get radix
	sscanf(argv[2], "%d", &radix);
	
	
	// Check if radix valid, use radix to interpret value
	if(radix == 8){
		sscanf(argv[1], "%o", &value);
	}else if(radix == 10){
		sscanf(argv[1], "%d", &value);
	}else if(radix == 16){
		sscanf(argv[1], "%x", &value);
	}else{
		printf("ERROR: Invalid radix\n");
		outValueErrs(opSize);
		return 0;
	}
	
	
	// If value could not be interpreted as a number, will still be set to default
	if(value == 2147483647){
		printf("ERROR: Invalid value\n");
		outValueErrs(opSize);
		return 0;
	}


	// Check if value fits in operand size
	if(abs(value) > maxUnsign){
		printf("ERROR: Value too large for operand size\n");
		outValueErrs(opSize);
		return 0;
	}else if((value > maxSign)||(value < ((-1*maxSign)-1))){
		printf("ERROR: Value outside bounds for signed numbers of operand size\n");
		outSignedErrs(value, opSize, 0);
		return 0;
	}else if(value < (-1*maxSign)){
		printf("ERROR: Value outside bounds for some signed representations of operand size\n");
		outSignedErrs(value, opSize, 1);
		return 0;
	}
	
	
	// All checks for invalid inputs have been passed, all inputs interpreted
	outFullTable(value, opSize);
	
	return 0;
}
