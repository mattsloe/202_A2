//
//  main.c
//  setBit
//
//  Created by Matt Loera on 1/31/22.
//
#include <stdio.h>
#include <stdlib.h>
int extractArgs(const char** args,unsigned long* intArray,int n);
int isFlipped(int,int,unsigned long* array);
void printBits(unsigned long toPrint);

int main(int argc, const char * argv[]) {
  unsigned long result = 0;
  long bitToSet = 0;
  if(argc == 1){
    printf("Error: no input");
    return 1;
  }
  for(int i=1; i<argc; i++){
    bitToSet = strtol(argv[i],NULL,0);
    if(bitToSet < 0 || bitToSet > 15){
      printf("Error: out of bounds");
      return 1;
    }
    result |= 1UL << bitToSet;
  }
  printBits(result);
  return 0; 
}

int extractArgs(const char** args,unsigned long* intArray,int n)
{
  for(int i = 0; i < n-1; i++){
    intArray[i] = strtoul(args[i+1],NULL,0);
    if(intArray[i] < 0 || intArray[i] > 15){
      printf("ERROR: out of bounds");
      return 0;
    }
  }
  return 0;
}

int isFlipped(int position,int arraySize,unsigned long * args)
{
  for(int i=0;i<arraySize;i++){
    if(args[i]==position) return 1;
  }
  return 0;
}

void printBits(unsigned long toPrint)
{
  int count= 4;
  for(unsigned long i = 1UL << 15; i > 0; i = i>>1){
    if(toPrint & i)
      printf("1");
    else
      printf("0");
    count--;
    if(count == 0){
      printf(" ");
      count = 4;
    }
  }
}
