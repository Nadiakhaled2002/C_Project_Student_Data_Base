#include <stdio.h>
#include <stdlib.h>

#include "std.h"

typedef struct SimpleDb
{
	uint32 Student_ID;
	uint32 Student_year;
	Int8 Student_Name[30];
	float Student_GPA;
	Int8 Student_Gender[10];
	/*
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
	*/
	struct SimpleDb* next;
} student;
//next is the ptr to struct that will carry the address of the next node in the linked list
 

bool sdb_isFull();
unit8 SDB_GetUsedSize();
bool SDB_AddEntry(uint32 student_id, uint32 student_year, Int8*Student_Name, float Student_GPA, Int8*Student_Gender);
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntryByID(uint32 id);
bool SDB_ReadEntryByNAME(Int8* name);
void SDB_GetList(unit8* count, uint32* list);
bool SDB_IsIdExist(uint32 id);
void sdb_app();
void sdb_action(unit8 choice);
bool SDB_update(uint32 id, uint32 student_year, float student_gpa, unit8 choise);