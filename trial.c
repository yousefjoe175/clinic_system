#include"STD.c"
#include<stdio.h>
typedef struct{
	u8 name[50];
	u8 age;
	u8 gender[10];
	u32 ID;
	u8 time;
}Patient;
	Patient patients[50];
	u8 slots[6] = {1,2,3,4,5,6}; //array to print the reservation slots
	u8 del[6] ={0}; //to remove the reserved slots and 0 to make the whole array zero so we can make comparison

void Reserve(void){
	//u8 r = idcompare();
	u8 r=1;
	
	if(r){		//r=1	//if the ID exist
	if((patients[r].time)==0){		//if the patient didn't reserve yet
	printf("The reservation slots are:\n");
	printf("1. 2:00 -> 2:30\n");	//the numbers before the time are the ones that used in indicating the time
	printf("2. 2:30 -> 3:00\n");
	printf("3. 3:00 -> 3:30\n");
	printf("4. 3:30 -> 4:00\n");
	printf("5. 4:00 -> 4:30\n");
	printf("6. 4:30 -> 5:00\n");
	
	for(u8 i=0;i<7;i++){			//for printing the available slots
	u8 b=0;
		for(u8 j=0; j<7;j++){	//for checking the reserved slots 
			if(slots[i]==del[j]){	//if one of the numbers of slots equals a number from del(number that admin enters later)
				b=1;			//for setting the condition that hide the reserved slot (true)
			}
		}
		if(b){					//the condition that hide the reserved slot
			continue;			//move to the next iteration without printing the line that contains the hided reservation
		}
		printf("Slot number %d is available\n",i+1);
	}

	printf("Choose a num: ");
	u8 x;
	printf("%d\n",r);
	scanf("%d",&x);
	printf("%d\n",r);
	//r=0
	del[x-1] = x; 	//insert the entered number in del so it can hide the line of that number
	patients[1].time = x;	//set the time of the patient to that number
	}else{//if the patient has already reservation	
		printf("You already have the #%d reservation",patients[r].time);	
	}
	}else{	//if there's no ID
		printf("There's no such ID!\n");
	}
}