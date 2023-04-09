#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STD.c"
#include"head.h"


extern u32 counter ; //counter for adding patients as it always increment when there's new patinet
extern Patient patients[50];
extern u8 slots[6]; //array to print the reservation slots
extern u8 del[6]; //to remove the reserved slots and to make the whole array zero so we can make comparison

void admin(void);

u8 strcompare(u8 *str1, u8 *str2){	//string compare
	 u8 i = 0;
	while(str1[i]!='\0' ||str2[i]!='\0' ){	//OR for that they can be equal in first word
		if(str1[i]==str2[i]){	//comparing char by char
			i++;
		}else{
			return 0;	//result for no equal
		} 
	}
	return 1;		//result for equal
}

u32 idcompare(void){	//ask for ID & check the existence of it and return the index of the struct array element
	u32 x;
	printf("Enter the ID: ");
	scanf("%d",&x);
	for(u8 i=1; i<50;i++){
		if(x==patients[i].ID){
			return i;
		}
	}
	return 0;
}

u8 login(){		//for opening the program and login
	u8 choice[10];
	printf("Welcome to IMT clinic!\n");
	printf("admin or user: ");
	scanf("%s",choice);	
	if(strcompare(choice,"admin")){
			u32 j =3;
			while(j>0){	//the loop for checking the 3 trials for entering password
				printf("You have %d trials\n",j);
				printf("Enter the password: ");
				u32 x;
				scanf("%d",&x);
					if(x==DEFAULTPASS){			//DEFAULTPASS= 1234
						printf("Correct password\n");
						return 1;	// if x = 1234, will return 1 to to move it to admin function
					}else{
						printf("invalid password!\t");
						j--;	//the trials decreases
					}
		}
	exit(0);	//when the trials ended the program exit
}else if(strcompare(choice,"user")){
	return 2; //in user we don't need password so it will return 2 tp move it to user function
}else{
	printf("Enter a valid choice! \n");	//in case of entering anything other than admin or user
	login();	//will restart the login function again
}

}

void addPatient(void){		//add new patient
	Patient* ptr = &patients[counter];	//a pointer that points at the new patient struct
	printf("Enter the name: ");
	scanf("%s",&(ptr->name));		//store the name
	printf("%s\n",ptr->name);
	
	printf("Enter the age: ");
	scanf("%u",&(ptr->age));		//store the age
	printf("%d\n",patients[counter].age);
	
	printf("Enter the gender: ");	//store the gender
	scanf("%s",&(ptr->gender));
	printf("%s\n",patients[counter].gender);
	
	ptr->time =0; //set the reservation to 0 to use latter in reverse function
	u32 x;
	printf("Enter ID: ");
	scanf("%u",&x);
	for(u8 i=1; i<counter;i++){
		if(x==patients[i].ID){
			printf("Taken ID!\n");
			printf("Try again!\n");
			addPatient();
		}
	}
			ptr->ID = x;	//set the ID value
			counter++;		//increment the counter for the next patient
			printf("Patient Added!\n");
			printf("%s\n",ptr->name);
			printf("%d\n",patients[counter-1].age);
			printf("%s\n",patients[counter-1].gender);
}

void Edit(void){	//editing any info about a patient
	u8 r = idcompare();	//r is the index of the struct array element
			printf("%s\n",patients[r].name);
			printf("%d\n",patients[r].age);
			printf("%s\n",patients[r].gender);
		if(r){	//as anything other than 0 is true so i put it directly in condition
			u8 x;
			u8 bool=1;
			while(bool){	//the loop for changing multiple things untill you set bool to 0
				printf("1.name\n2.age\n3.gender.\n4.exit.\n");
				printf("Choose: ");
				scanf("%d",&x);
				switch (x){
					case 1:
					printf("Enter the name: ");
					scanf("%s",&patients[r].name);
					printf("name: %S\n",patients[1].name);
					break;
					
					case 2:
					printf("Enter the age: ");
					scanf("%d",&patients[r].age);
					printf("age: %s\n",patients[r].age);
					break;
					
					case 3:
					printf("Enter the gender: ");
					scanf("%s",&patients[r].gender);
					printf("gender: %s\n",patients[r].gender);
					break;
					
					case 4:
					bool =0;
					break;
					
					default:
					printf("Enter a valid number!\n");
					Edit();
					break;
					}
				}
		}else{
			printf("There's no such ID!\n");
			Edit();
		}
	
}

void Reserve(void){
	u8 r = idcompare();
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
	//r=1
	scanf("%d",&x);
	//r=0
	del[x-1] = x; 	//insert the entered number in del so it can hide the line of that number
	patients[1].time = x;	//set the time of the patient to that number
	}else{//if the patient has already reservation	
		printf("You already have the #%d reservation\n",patients[r].time);	
	}
	}else{	//if there's no ID
		printf("There's no such ID!\n");
	}
}

void Cancel(void){	//to cancel the reservation of the patient
	u8 i = idcompare();
	u8 x;
	x = patients[i].time;
	del[x-1] =0;	//to set the element containing the value to be hidden to 0
	patients[i].time= 0;	//set the time of reservation to 0 (no reservation)
	printf("The reservation cancelled successfuly!\n");
	printf("Do you want to reserve another appointment? enter \"yes\": ");
	u8 y[10];	
	scanf("%s",&y);	//ask for string 
	u8 r = strcompare(y,"yes");	//if string == yes will get into reserve function
	if(r){
		Reserve();
	}else{
		admin();	// not true, get back to admin function
	}
}

void viewPatient(u32 i){ //just print out the main infos of the patient
	printf("name:\t%S\n",patients[i].name);
	printf("age:\t%s\n",patients[i].age);
	printf("gender:\t%s\n",patients[i].gender);
	
}

void viewReserve(u32 i){	//show the reservation of the patient
	
	
	if(patients[i].time==0){	//if there's no reservation 
		printf("You have no reservation yet!\n");
	}else{
		
	printf("Your reservation is: ");
		switch (patients[i].time){
			case 1: printf(" 2:00 -> 2:30\n");
			break;
			
			case 2: printf(" 2:30 -> 3:00\n");
			break;
			
			case 3: printf(" 3:00 -> 3:30\n");
			break;
			
			case 4: printf(" 3:30 -> 4:00\n");
			break;
			
			case 5: printf(" 4:00 -> 4:30\n");
			break;
			
			case 6: printf(" 4:30 -> 5:00\n");
		}
	}
	}

void user(u8 r){	//handles the user part
	if(r){
		u8 x;
	printf("1.view patient record.\n");
	printf("2.view today's reservation.\n");
	printf("3.exit the program.\n");
	printf("Choose: ");
	scanf("%d",&x); 
	
	switch (x){
		case 1: viewPatient(r);
		break;
		
		case 2: viewReserve(r);
		break;
		
		case 3: exit(0);
		default:
		printf("Enter a valid number!\n");
	}

	}else{	//if x != 1,2,3 then will reask him for ID and restart user function again
		printf("Enter a valid ID!\n");
		r= idcompare();
	}
	user(r);
}
	
void admin(void){
	u8 choice,r;	//choice for choosing the options below, r for storing the ID index in case 5.
	printf("1.Add new patient.\n");
	printf("2.Edit patinet record.\n");
	printf("3.Reserve a slot with the doctor.\n");
	printf("4.Cancel reservation.\n");
	printf("5.change to user mode.\n");
	printf("6.Exit the program.\n");
	printf("Choose: ");
	scanf("%d",&choice);
	switch (choice){
		case 1:	addPatient();
		break;
		
		case 2: Edit();
		break;
		
		case 3: Reserve();
		break;
		
		case 4: Cancel();
		break;
		
		case 5:
		 r = idcompare();
		user(r);
		break;
		
		case 6: exit(0);
		
		default: printf("Enter a valid number! \n");
	}
	admin();	//in all ways except case 6 it will get the user back to admin after finishing any case
}

