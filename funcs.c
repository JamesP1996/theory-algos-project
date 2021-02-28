#include <stdio.h>
#include <inttypes.h>

// Definitions of Commonly Used Data Types (uint32_t, PRIX32)
#define WORD uint32_t
#define PF PRIX32
// uint32_t CH function, returns X AND Y XOR Exclusive X AND Z
#define CH(x,y,z) (x&y)^(~x&z)
// uint32_t Maj function, returns X AND Y XOR X AND Z XOR Y AND Z
#define MAJ(x,y,z) (x&y)^(x&z)^(y&z)
// Main Function to Run Code
int main(int argc, char *argv[]){
	// Setup Variables as Hexadecimal	
	WORD x = 0x0F0F0F0F;
	WORD y = 0x0A0A0A0A;
	WORD z = 0xB0B0B0B0;
	// Return answers of CH/Maj Functions to Variables 
	WORD ans1 = CH(x,y,z);
	WORD ans2 = MAJ(x,y,z);
	// Print the Inputs and return values of both Ch, Maj Functions
	printf("Ch(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n",x, y, z, ans1);
	printf("Maj(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n",x, y, z, ans2);
}
