#include <stdio.h>
#include <stdlib.h>

#include "std.h"

typedef struct SimpleDb
{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
	struct SimpleDb* next;
} student;
//next is the ptr to struct that will carry the address of the next node in the linked list
 

bool sdb_isFull();
unit8 SDB_GetUsedSize();
bool SDB_AddEntry(uint32 student_id, uint32 student_year, uint32 course1_id,
	uint32 course1_grade, uint32 course2_id, uint32 course2_grade, uint32 course3_id,
	uint32 course3_grade);
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(unit8* count, uint32* list);
bool SDB_IsIdExist(uint32 id);
void sdb_app();
void sdb_action(unit8 choice);