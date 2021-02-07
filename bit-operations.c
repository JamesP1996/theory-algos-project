#include <stdio.h>

void bin_print(unsigned int i)
{
    // Number of bits in an integer.
    int j = sizeof(unsigned int) * 8;

    // Temporary Variable 
    int k;
    
    // Loop over the Bits in I
    for(j--;j >= 0; j--){
	 //  
   	 k = ((1 << j) & i) ? 1 : 0;
	 // Print K
	 printf("%d",k);
    }
}

// Standard Main Signature
int main(int argc, char *argv[])
{
    // Set I to a Literal Value;
    unsigned int i = 0xffffffff;
    
    // What we're printing.
    printf("Original: ");
    // Print i in binary
    bin_print(i);
    // End Line.
    printf("\t%x\t%u\n",i,i);
    
    for(int j = 0; j < 40; j++)
    {
    // What the operation is.
    printf("%3u << %2d " , i, j);
    // i Shifted Left << j times
    bin_print(i << j);
    printf("\n");

    }
    // End the Main Function
    return 0;
}
