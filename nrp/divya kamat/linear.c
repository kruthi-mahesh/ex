#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 15

//item type in the hash table
typedef struct i
{
	char name[15];
	long int phno;
}Item;

//hash table structure
typedef struct t
{
	Item* data[size];
	int count;
}Table;


int count = 0;

//this function returns the index of the key in the hash table.
int HashFunction(char input[])
{
	int sum=0, i, ind;
	for(i = 0; input[i]!='\0' ; i++)
		sum += (int)input[i];
	ind = sum % 15;
	return ind;
}

void InputTable(FILE *table, FILE *input)
{
	Item *newItem = (Item*)malloc(sizeof(Item));
	Table t;
	int index, i;

	input = fopen("input.txt", "rb");
	table = fopen("table.txt", "rb");
	if(input == NULL || table == NULL)
	{
		printf("\n Sorry, unable to locate file. ");
		exit(0);
	}

	fread(&t, sizeof(Table), 1, table);
	fseek(input, t.count*sizeof(Item), SEEK_SET);

	fread(newItem, sizeof(Item), 1, input);

	fclose(table);
	//get index in the table
	index = HashFunction(newItem->name);
	//linear probing
	for(i=index; i<size ; i++)
	{
		//look for empty spot from obtained index to the end of array
		if(t.data[i] == NULL)
		{
			t.count++;
			t.data[i] = newItem;
			goto ret;
		}
	}
	if(i == size)
	{
		for(i=0 ; i<index ; i++)
		{
			if(t.data[i] == NULL)
			{
				t.count++;
				t.data[i] = newItem;
				goto ret;
			}
		}
		//array full
		if(i == index)
		{
			printf("\n Cannot be inserted. ");
			exit(0);
		}
	}

	//write the table to the file
	ret : 
	table = fopen("table.txt", "wb");
	fwrite(&t, sizeof(Table), 1, table);
	fclose(table);
	fclose(input);
}

//print the details of item
void print(Item *i)
{
	printf(" \n Name : %s \n Contact : %ld ", i->name, i->phno);
}

//to search for key in hash table
void SearchKey(FILE *table)
{
	char key[15];
	int index, i;

	printf("\n Enter the key to be searched : ");
	scanf("%s",key);
	index = HashFunction(key);
	Table t;
	table = fopen("table.txt", "rb");
	//read the table
	fread(&t, sizeof(Table), 1, table);

	//starting with index obtained, search in the entire array
	for(i=index; (i<size) || (t.data[i]==NULL) ; i++)
	{
		if(!strcmp(key, t.data[i]->name))
		{
			printf("\n Search Successfull! ");
			print(t.data[i]);
			return;
		}
	}
	//if search unsuccessful on the indexes after 'index', search on indexes before 'index'
	if(index == size)
	{
		for(i=0; (i<index) || (t.data[i]==NULL) ; i++)
		{
			if(!strcmp(key, t.data[i]->name))
			{
				printf("\n Search Successfull! ");
				print(t.data[i]);
				return;
			}
		}
	}
	printf("\n Unsuccessful search. ");
	fclose(table);
}
	
		
//to display contents of hash table
void DisplayTable(FILE *fptr)
{
	int j;
	fptr = fopen("table.txt", "r");
	printf("\n Contents of Hash Table are : ");
	Item i;
	Table t;
	//read hash table from file
	fread(&t, sizeof(Table), 1, fptr);
	//print the table
	for(j=0; j<size ; j++)
	{
		printf("\n Index %d :  %s", j, t.data[j]->name);
	}
	fclose(fptr);
}

//to input entries to file input.txt
void InputFile(FILE *input)
{
	Item *i = (Item*)malloc(sizeof(Item));
	count++;
	printf("\n Enter the name of the customer : ");
	scanf("%s", i->name);
	printf("\n Enter the contact number : ");
	scanf("%ld", &i->phno);

	input = fopen("input.txt", "a+b");
	if(input == NULL)
	{
		printf("\n Sorry, unable to locate file. ");
		exit(0);
	}
	fwrite(i, sizeof(Item), 1, input);
	fclose(input);
}

//to display entries from input.txt
void DisplayFile(FILE *input)
{
	Item i;
	int j = 0;
	input = fopen("input.txt", "r");
	if(input == NULL)
	{
		printf("\n Sorry, unable to locate file. ");
		exit(0);
	}
	printf("\n The records in the input file are : ");
	while(fread(&i, sizeof(Item), 1, input) != EOF && j<count) 
	{
		printf("\n Record %d : ", j++);
		print(&i);
	}
	fclose(input);
}

void main()
{
	Table tab;
	int i, choice;

	tab.count = 0;
	for(i=0; i<size ; i++)
		tab.data[i] = NULL;

	FILE *ftable, *finput;
	ftable = fopen("table.txt", "w+b");
	fwrite(&tab, sizeof(Table), 1, ftable);
	fclose(ftable);
	finput = fopen("input.txt", "wb");
	fclose(finput);
	while(1)
	{
		printf("\n 1) Enter inputs to file \n 2) Display File \n 3) Enter elements in the table \n 4) Search for key \n 5) Display Hash Table \n 6) Exit \n Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : InputFile(finput);
				 break;
			case 2 : DisplayFile(finput);
				 break;
			case 3 : InputTable(ftable, finput);
				 break;
			case 4 : SearchKey(ftable);
				 break;
			case 5 : DisplayTable(ftable);
				 break;
			case 6 : exit(0);
			default : printf("\n Invalid choice. ");
		}
	}
}
