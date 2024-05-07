#include <reg51.h>
#include <stdio.h>
void main(){
  int i;
  int j;
  int k;
  while(1){
    for(i=0;i<256;i++)
    {
      P1=i;
      for(j=0;j<1000;j++)
      {
        for(k=0;k<100;k++);		
      }
    }
  }
}
