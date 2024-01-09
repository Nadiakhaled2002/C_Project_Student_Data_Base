#include "sdb.h"


void sdb_app()
{
	//this func will take the choice from the user and will only break if the  user enters 0
	int num;
	
	printf("enter 1 to add entry:\n");
	printf("enter 2 to get used size:\n");
	printf("enter 3 to read a student data:\n");
	printf("enter 4 to get list of student ids:\n");
	printf("enter 5 to check if id existed:\n");
	printf("enter 6 to delete student data:\n");
	printf("enter 7 to check if database is full:\n");
	scanf("%d", &num);
	while (num)
	{
		
	
		sdb_action(num);

		printf("to exit press 0 to cont choose another num :\n");
		scanf("%d", &num);
		


	}



}
void sdb_action(unit8 choice) 
{
	//here is the data of the student saved 
	uint32 stid=0;
	uint32 styr=0;
	uint32 stc1id=0;
	uint32 stc1gr=0;
	uint32 stc2id=0;
	uint32 stc2gr=0;
	uint32 stc3id=0;
	uint32 stc3gr=0;
	// this switch will take the choice from sdb app and match it with the function
	switch (choice)
	{
	case 1:
	{
		printf("Enter the data:\n");
		scanf("%d%d%d%d%d%d%d%d", &stid, &styr, &stc1id, &stc1gr, &stc2id,
			&stc2gr, &stc3id, &stc3gr);
		bool f = SDB_AddEntry(stid,styr,stc1id,stc1gr,stc2id,stc2gr,stc3id,stc3gr);
		
		if (f)
			printf("the data is added\n");
		else
			printf("data is not added \n");

		break;
	}
	case 2:
	{

		printf("the used  size is %d:\n",SDB_GetUsedSize());
		break;
	}
	case 3:
	{
		printf("enter the id you want to view the data for:\n");
		scanf("%d", &stid);
		SDB_ReadEntry(stid);
		break;
	}
	case 4:
	{
		uint32 arr[10] ;
		unit8 num;
		printf("enter how many ids you want to check the data of :\n");
		scanf("%d", &num);
		printf("enter the id nums:\n");
		//this for loop takes the data from user
		for (unit8 i = 0; i < num; i++)
		{
			scanf("%d", &arr[i]);
			
		}
		SDB_GetList(&num, arr);
		break;
	}
	case 5:
	{
		printf("enter the id num:\n");
		scanf("%d", &stid);
		int x=SDB_IsIdExist(stid);
		if (x)
			printf("the id exist\n");
		else
			printf("the id doesnt exist\n");
		break;
	}
	case 6:
	{
		printf("enter the student id you want to delete:\n");
		scanf("%d", &stid);
		SDB_DeletEntry(stid);
		break;
   
	}
	case 7:
	{
		bool y = sdb_isFull();
		if (y)
			printf("it is full\n");
		else
			printf("not full\n");
		break;

	}
	}

}


