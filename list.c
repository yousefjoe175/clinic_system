#include<stdio.h>
#include"STD.c"
#include<string.h>
extern node head;
extern u8 arrlength;

void add(u8 *dude){
	node* last = &head;
	if(arrlength ==0){
		last -> id = arrlength;
		strcpy(last -> time,dude);
		last -> next = NULL;
	}else{
		node* new = (node*) malloc(sizeof(node));
		last -> id = arrlength;
		strcpy(last -> time,dude);
		new-> next = NULL;
		while(last->next != NULL){
			last = last->next;
		}
		last -> next = new;
	}
	arrlength++;
}

void print(void){
	node* last = &head;
	while(last-> next != NULL){
		printf("%s \n",last->time);
		last = last->next;
	}
	printf("%s \n",last->time);
}
