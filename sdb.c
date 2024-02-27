#include "sdb.h"
#include <string.h> 
student* head = NULL;
//i created a pointer to struct name head to point to the biggening of the single linked list carrying null
bool sdb_isFull()
{
	int count = 0;
	//i created an integer named count to count how many nodes are in the linked list 
	student* ptr = head;
	//and then i created a pointer to struct carring the address saved in the head which is the first node address 
	while (ptr!= NULL)
	{
		ptr = ptr->next;
		count++;
	}
	//the while function will loop until the ptr reaches the last node which will carry null and then the loop will end 
	//inside the while i will increment the count every iritation untill i reach null
	if (count == 10)
		return true;
	else
		return false;
	//here the if checks if the count == 10 then it is full else it is not full
}

unit8 SDB_GetUsedSize()
{
	//the same as sdb_isfull() except that it will return the number of data
	int count = 0;
	student* ptr = head;
	
	while (ptr!= NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;

}

bool SDB_AddEntry(uint32 student_id, uint32 student_year, Int8*Student_Name,
	float Student_GPA, Int8*Student_Gender)
{
	//i initialised the node then allocated it
	student *temp = (student*)malloc(sizeof(student));
	if (head == NULL)
	{
		//to add a new node at the beginning the head must be = NULL then adding the data inside each node
		temp->Student_ID = student_id;
		temp->Student_year = student_year;
	
		strcpy(temp->Student_Name, Student_Name);
		temp->Student_GPA = Student_GPA;
		strcpy(temp->Student_Gender, Student_Gender);
		temp->next = head;
		head = temp;
		//make the next pointer pointer carry null
		
		//the head now carryis the address of the first node
		
	}
	//if checks if there is more room to add node then returns 1 if it is not full
	if (sdb_isFull() != true)
	{
		//adding nodes at the end and adding the new data inside the node
		temp->Student_ID = student_id;
		temp->Student_year = student_year;
		strcpy(temp->Student_Name, Student_Name);
		temp->Student_GPA = Student_GPA;
	
		 strcpy(temp->Student_Gender, Student_Gender);
		// 
		//ptr is a pointer to struct that carryis the address of the head which is the first node address 
		student* ptr = head;
		//while function will loop until it reaches the node before the last 
		while (ptr->next!= NULL)
		{
			ptr = ptr->next;

		}
		//the last pointer will carry the address of the temp node created 
		ptr->next = temp;
		// assigning the last node next pointer  to carry null
		temp->next = NULL;
		return 1;
	}
	
	else
		return 0;

}

void SDB_DeletEntry(uint32 id)
{
	//temp is a pointer to struct we will use it to save the node that will be deleted 
	student* temp = NULL;
	//if the id was first  at the first node then delete 
	if (head->Student_ID == id)
	{
		temp = head;
		head = head->next;
		free(temp);

	}

	//ptr is a pointer to struct carrying the first node address
	student* ptr = head;
	// while checks if the node after the node i am pointing to carrying null or not
	while (ptr->next != NULL)
	{
		// if the next node is carrying the data i want to delete the function will break out of the while loop 
		if (ptr->next->Student_ID == id)
		{
			break;
		}
		// this will iritate untill the ptr reaches the node with the data to be deleted 
		ptr = ptr->next;
	}
	//if checks if the next  node's pointer is carrying null or not
	if (ptr->next != NULL)
	{
		//if the next node's pointer is not carrying null then then the next node data is the data to be deleted so it will be saved inside the temp 
		temp = ptr->next;
		//the next pointer will carry the adress of the node after the node that will be deleted 
		ptr->next = temp->next;
		free(temp);//deleted the node
	}



}

bool SDB_ReadEntryByID(uint32 id)
{
	//checking if the added is 3 students or less if true print else do not print
	//if (SDB_GetUsedSize() >= 3) {
		//temp is the pointer that points to the nodes inside the linked list
		student* temp = NULL;
		temp = head;
		// while will loop until the temp pointes to the last node carrying null in the next pointer
		while (temp != NULL)
		{
			//if checks the id that is to be pretned 

			if (temp->Student_ID == id)
			{
				//printing the data inside the node then breaking out of the while
				printf("Student Id: %d\n", temp->Student_ID);
				printf("Student year: %d\n", temp->Student_year);
				
				
					printf("name: %s\n", temp->Student_Name);
				
				printf("student gpa: %.2f\n", temp->Student_GPA);
				printf("student gender: %s\n", temp->Student_Gender);
				
				break;

			}
			//the temp pointer is incremented to point to the next node to search for the data that is to be printed 
			temp = temp->next;
		}

		if (temp == NULL)
		{
			return 0;

		}
		else
			return 1;
	//}
	//else
		//printf("the min is 3 students add more\n");
}

bool SDB_ReadEntryByNAME(Int8* name)
{

	
	//checking if the added is 3 students or less if true print else do not print
	//if (SDB_GetUsedSize() >= 3) {
		//temp is the pointer that points to the nodes inside the linked list
	student* temp = NULL;
	temp = head;
	unit8 flag = 0;
	unit8 flag0 = 0;
	// while will loop until the temp pointes to the last node carrying null in the next pointer
	while (!flag)
	{
		//if checks the id that is to be pretned 

		if (strcmp(temp->Student_Name, name) == 0)
		{
			flag0 = 1;
			//printing the data inside the node then breaking out of the while
			printf("Student Id: %d\n", temp->Student_ID);
			printf("Student year: %d\n", temp->Student_year);


			printf("name: %s\n", temp->Student_Name);

			printf("student gpa: %.2f\n", temp->Student_GPA);
			printf("student gender: %s\n", temp->Student_Gender);

			break;

		}
		//the temp pointer is incremented to point to the next node to search for the data that is to be printed 
		if (temp->next == NULL)
		{
			flag = 1;
		}
		temp = temp->next;
	}

	if (flag0==1)
	{
		return 1;

	}
	else
		return 0;
	//}
	//else
		//printf("the min is 3 students add more\n");
}

void SDB_GetList(unit8* count, uint32* list)
{
	
	
	
		student* ptr = head;
		
		// the for loop is to print the ids that was taken in an array it will loop until it reaches the number of data the user want to search for
		for (unit8 i = 0; i < (*count); i++) {
			//while is to loop all the linked list until it finds the data and will start from the beginning of the linked list so the data doesnt have to be sorted 
			while (ptr != NULL)
			{
				//when the data is found the if function prints the data and breaks out of the while
				if (ptr->Student_ID == list[i])
				{
					printf("Student Id: %d\n", ptr->Student_ID);
					printf("Student year: %d\n", ptr->Student_year);


					printf("name: %s\n", ptr->Student_Name);

					printf("student gpa: %.2f\n", ptr->Student_GPA);
					printf("student gender: %s\n", ptr->Student_Gender);
					break;

				}
				ptr = ptr->next;//ptr is inc to irritate the linked list  

			}
			ptr = head;// ptr carries the first address of the node to start searching from the beg.
		}
			
		




}

bool SDB_IsIdExist(uint32 id)
{
	student* ptr = head;
	unit8 flag=0;
	unit8 flag0;
	//while function loops through the linked list until it reaches the node before the last 
	while (!flag)
	{
		//if the data is found it will break out of the while
		if (ptr->Student_ID == id)
		{
			flag0 = 1;
			break;

		}
		if (ptr->next == NULL)
		{
			flag = 1;
		}
		ptr = ptr->next;
	}
	if (flag0 == 1)
	{
		return 1;
	}
	else
		return 0;


}
bool SDB_update(uint32 id,uint32 student_year, float student_gpa, unit8 choise)
{
	student* ptr = head;
	unit8 flag = 0;
	unit8 flag0;
	//while function loops through the linked list until it reaches the node before the last 
	while (!flag)
	{
		//if the data is found it will break out of the while
		if (ptr->Student_ID == id)
		{
			flag0 = 1;
			switch (choise)
			{
			case 0:
			{
				ptr->Student_year = student_year;
				break;
			}
			case 1:
			{
				ptr->Student_GPA = student_gpa;
				break;
			}
			}
			
			break;

		}
		if (ptr->next == NULL)
		{
			flag = 1;
		}
		ptr = ptr->next;
	}
	if (flag0 == 1)
	{
		return 1;

	}
	else
	{
		
		return 0;
	}
}

