/* PES Project One Program Three */

#include<stdio.h>
#include<stdint.h>

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

void testBits(uint16_t value)
{
	uint8_t onBitCnt = 0;
	uint16_t bitTestVal = value;
	
	for(uint8_t i = 0; i<4; i++){
		if((bitTestVal & 0x1) == 1){
			onBitCnt++;
		}
		bitTestVal = bitTestVal>>1;
	}
	
	printf(" %s\n", binaryStr(value, 16));
	if(onBitCnt >=3){
		printf(" 3 of Last 4 Bits On = TRUE\n");
	}else{
		printf(" 3 of Last 4 Bits On = FALSE\n");
	}
	
	return;
}


int main(void)
{
	//uint16_t input = 0xFACE;
	union VALUE {
		struct{
			uint8_t b1;
			uint8_t b2;
		}bytes;
		uint16_t full;
	};
	union VALUE input;
	union VALUE inputCpy;
	
	input.full = 0xFACE;
		
	
	// Original Input
	printf("Original Input:\n %#X\n", input.full);
	testBits(input.full);
	
	// Reverse Bytes
	inputCpy.bytes.b1 = input.bytes.b2;
	inputCpy.bytes.b2 = input.bytes.b1;
	printf("Reverse Bytes:\n %#X\n", inputCpy.full);
	testBits(inputCpy.full);
	
	//Rotate 6 Bits Left
	inputCpy.full = (inputCpy.full << 6)|(inputCpy.full >> (16 - 6));
	printf("Rotate 6 Bits Left:\n %#X\n", inputCpy.full);
	testBits(inputCpy.full);
	
	//Rotate 4 Bits Right
	inputCpy.full = (inputCpy.full >> 4)|(inputCpy.full << (16 - 4));
	printf("Rotate 4 Bits Right:\n %#X\n", inputCpy.full);
	testBits(inputCpy.full);
	
	return 0;
	
}
