#ifndef _HEAD_H
#define _HEAD_H
#define DEFAULTPASS 1234
typedef struct{
	u8 name[50];
	u8 age;
	u8 gender[10];
	u32 ID;
	u8 time;
}Patient;
u32 counter = 1; 
Patient patients[50];
u8 slots[6] = {1,2,3,4,5,6};
u8 del[6] ={0}; 

u8 strcompare(u8 *str1, u8 *str2);
u32 idcompare(void);
u8 login();
void addPatient(void);
void Edit(void);
void Reserve(void);
void Cancel(void);
void viewPatient(u32 i);
void viewReserve(u32 i);
void user(u8 r);
void admin(void);

#endif