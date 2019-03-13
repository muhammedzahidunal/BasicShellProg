#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            break;
         }
 }
 return number;
}
int main(int argc,char *argv[]){
	int sayi1= strtoint(argv[0]);
	int sayi2= strtoint(argv[1]);
	if(sayi1 != -1 && sayi2 != -1){
	int sonuc=sayi1/sayi2;
	printf("%d / %d = %d\n",sayi1,sayi2,sonuc);
	}
	else{
		printf("int tipinde bir input giriniz\n");	
	}
}
