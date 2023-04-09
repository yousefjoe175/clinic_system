#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STD.c"
#include"fun.c"




void main (void){
	
	u8 x =login();
	if(x==1){
		admin();
		
	}else if(x==2){
		u8 r = idcompare();
		user(r);
	}
}