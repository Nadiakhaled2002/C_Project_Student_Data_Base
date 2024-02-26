#include "sdb.h"
#include <string.h> 
static unit8 stcount;


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
	printf("enter 8 to edit student data:\n");
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
	Int8 stname[30];
	float stgpa=0;
	Int8 stgender[1];
	// this switch will take the choice from sdb app and match it with the function
	switch (choice)
	{
	case 1:
	{
		unit8 count=0;
		unit8 x=0;
		unit8 y=0;
		unit8 r=0;
		unit8 flag = 1;
		unit8 flag1 = 1;
		unit8 flag2 = 1;
		unit8 flag3 = 1;
		unit8 flag4 = 1;
		uint32 a;
		printf("Enter the ST_id ST_year  gpa gender:\n");
		scanf("%d%d%f%s", &stid, &styr, &stgpa, &stgender);
		printf("enter name:\n");
		scanf(" %[^\n]", stname);
		
		while (flag)
		{
			a = stid;
			while (a != 0)
			{


				a = a / 10;
				count++;
			}
			if (stcount >= 1)
				x = SDB_IsIdExist(stid);
			else
				x = 0;
			if ((x == 1) || (count != 7))
			{
				printf("please enter a unique ID that is 7 digits\n");
				scanf("%d", &stid);
				
			}
			else
			{
				
				flag = 0;
			}
			x = 0;
			a = 0;
			count = 0;
		}
		while (flag1)
		{
			if ((stgender[0] != 'F') && (stgender[0] != 'M'))
			{
				printf("pleases choose F or M for gender:\n");
				scanf("%s", &stgender);
			}
			else
				flag1 = 0;
		}
		while (flag2)
		{
			if ((styr > 5) || (styr == 0))
			{
				printf("please enter years between 1 and 5\n");
				scanf("%d", &styr);
			}
			else
				flag2 = 0;
		}
		while (flag3)
		{
			if (stgpa > 4.00 || (stgpa == 0.00))
			{
				printf("please enter gpa between 0 and 4\n");
				scanf("%f", &stgpa);
			}
			else
				flag3 = 0;
		}
		
		while (flag4)
		{
			
			if (strchr(stname, ' ') != NULL)
			{
				flag4 = 0;
			}
			else
			{
				printf("please enter your first and last name\n");
				scanf(" %[^\n]",stname);
			}
		}

		
		bool f = SDB_AddEntry(stid,styr,stname, stgpa, stgender);
		
		if (f)
		{
			printf("the data is added\n");
			stcount++;
		}
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
		unit8 choise;
		printf("enter the 0 for getting data by ID or 1 for name:\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 0:
		{
			printf("enter the id\n");
			scanf("%d", &stid);
			uint32 a = 0;
			uint32 x = 0;
			unit8 flag = 0;
			unit8 count = 0;
			while (flag)
			{
				a = stid;
				while (a != 0)
				{


					a = a / 10;
					count++;
				}
				if (stcount >= 1)
					x = SDB_IsIdExist(stid);
				else
					x = 0;
				if ((x == 1) || (count != 7))
				{
					printf("please enter a unique ID that is 7 digits\n");
					scanf("%d", &stid);

				}
				else
				{

					flag = 0;
				}
				x = 0;
				a = 0;
				count = 0;
			}
			
			int z = SDB_ReadEntryByID(stid);
			if (z)
				printf("done\n");
			else
				printf("no student found\n");
			break;
		}
		case 1:
		{
			unit8 flag4 = 1;
			printf("enter  name:\n");
			scanf(" %[^\n]", &stname);
			while (flag4)
			{

				if (strchr(stname, ' ') != NULL)
				{
					flag4 = 0;
				}
				else
				{
					printf("please enter your first and last name\n");
					scanf(" %[^\n]", stname);
				}
			}
			int y = SDB_ReadEntryByNAME(stname);
			if (y)
				printf("done\n");
			else
				printf("no student found with that name\n");
		}

		}
		
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
	
		uint32 a=0;
		uint32 x=0;
		unit8 flag = 0;
		unit8 count = 0;
		while (flag)
		{
			a = stid;
			while (a != 0)
			{


				a = a / 10;
				count++;
			}
			if (stcount >= 1)
				x = SDB_IsIdExist(stid);
			else
				x = 0;
			if ((x == 1) || (count != 7))
			{
				printf("please enter a unique ID that is 7 digits\n");
				scanf("%d", &stid);

			}
			else
			{

				flag = 0;
			}
			x = 0;
			a = 0;
			count = 0;
		}
		SDB_DeletEntry(stid);
		printf("Done\n");
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
	case 8:
	{
		unit8 choise;
		uint32 newyear;
		uint32 newgpa;
		uint32 id;
		printf("enter id and current year then enter 0 for year and 1 for gpa:\n");
		scanf("%d%d%d", &id,&newyear,&choise);
		switch (choise)
		{
		case 0:
		{
			printf("enter new year\n");
			scanf("%d", &newyear);
			break;
		}
		case 1:
		{
			printf("enter new gpa\n");
			scanf("%d", &newgpa);
			break;
		}
		}
		int y = SDB_update(id, newyear,newgpa,choise);
		if (y)
		{
			printf("done\n");
		}
		else
			printf("student not found\n");
		break;

	}
	}

}


