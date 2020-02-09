#include <stdio.h>
#include "platform.h"
#include <xparameters.h>
#include <multiply.h>

// macros for register addresses and offsets
#define MULTIPLY_ADDR XPAR_MULTIPLY_0_S00_AXI_BASEADDR
#define REG_1_OFFSET MULTIPLY_S00_AXI_SLV_REG0_OFFSET
#define REG_2_OFFSET MULTIPLY_S00_AXI_SLV_REG1_OFFSET
#define REG_3_OFFSET MULTIPLY_S00_AXI_SLV_REG2_OFFSET

void print(char *str);

int main()
{
    init_platform();

    // multiplicants
    u32 multiplicant1[5] = {1, 3, 5, 7, 9, 11};
    u32 multiplicant2[5] = {2, 4, 6, 8, 10, 12};
    
    u32 res; // store the response
    int loopCounter = 0; // loop counter

    for(loopCounter; loopCounter < 6; loopCounter++){
        
	// write to the registers
	MULTIPLY_mWriteReg(MULTIPLY_ADDR, REG_1_OFFSET, multiplicant1[loopCounter]);
	MULTIPLY_mWriteReg(MULTIPLY_ADDR, REG_2_OFFSET, multiplicant2[loopCounter]);

	// check the values in the registers
	// pull and print the results
	printf("Multiplicant = %x\n", MULTIPLY_mReadReg(MULTIPLY_ADDR, REG_1_OFFSET));
	printf("Multiplicant = %x\n", MULTIPLY_mReadReg(MULTIPLY_ADDR, REG_2_OFFSET));
	printf("Multiplication result = %x\n", 
	       MULTIPLY_mReadReg(MULTIPLY_ADDR, REG_3_OFFSET));
    }
    cleanup_platform();
    return 0;
}
