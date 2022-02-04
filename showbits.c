//  showBits
//
//  Created by Matt Loera on 2/3/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long commonBits(const char*,const char*);
void outputResults(unsigned long result);
void printBits(unsigned long);
unsigned long takeTwoC(unsigned long);
int main(int argc, const char * argv[]) {
  //validate input
  if(argc != 3){
    printf("Error: please provide two hexadecimal numbers as arguments to the program.");
    return -666;
  }
  
  //and mask the inputs
  unsigned long result = commonBits(argv[1],argv[2]);
  
  //output
  if(result != 0){
    printBits(result);
  }else{printf("No Bits in common. ");}
  printf("Hexadecimal: %x, ",(unsigned int)result);
  printf("Signed: %d, ",(int)result);
  printf("Unsigned: %u.",(int)result);
  
  return 0;
}

unsigned long commonBits(const char* str1, const char* str2)
{
  unsigned long num1 = strtol(str1,NULL,0);
  unsigned long num2 = strtol(str2,NULL,0);
  return num1 & num2;
}

void printBits(unsigned long toPrint)
{
  char commonBits[100]={'\0'};
  char buf[4]={'\0'};
  printf("Bits ");
  for(int i=0; i < 32; i++){
    if(toPrint & (1UL<<i)){
      snprintf(buf,4,"%d,",i);
      strncat(commonBits,buf,4);
    }
  }
 // commonBits[strlen(commonBits)-1] = '\0';
  printf("%s",commonBits);
  printf(" in common. ");
}
