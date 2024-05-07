#include<studio.h>
#include<reg51.h>
int main
{
  int i;
  while(1)
  {
    P1=0xFF;
    for(i=0; i<50 ; i++)
    {
    }
    P1=0x00;
    for(i=0; i<50 ; i++)
    {
    }
 }
}
