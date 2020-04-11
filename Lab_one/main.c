#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include"Test.h"
#include "options.h"

int interface() {
	int array_size,array_size2;
	int elem_type;

	printf("Write the size of the array:  ");
	scanf_s("%d", &array_size);
	printf("What type of data do you want to work with? \n");
	elem_type = type_of_element(); //выбор типа данных
	//Array *mass = (void*)malloc(sizeof(Array));
	Array *mass = create_mass(array_size, elem_type); //создание массива
	printf(" Choose the operation:\n"
		"1. Print array \n"
		"2. Sorting\n"
		"3. Map\n"
		"4. Where\n"
		"5. Concatination\n"
		"6. get the test\n"
		"7. exit\n"
		"Your choice: ");
	int choice = 0;
	scanf_s("%d", &choice); printf("\n");
	Array* mass1;// = (Array*)malloc(sizeof(Array));
	Array* mass2;
	Array* mass3;
	
   		switch (choice)
		{
		case 1:
			print_mass(mass);
			break;
		case 2:
			sort_mass(mass);
			printf("Sorted array:\n");
			print_mass(mass);
			break;
		case 3:
			map(mass);
			print_mass(mass);
			break;
		case 4: 
			mass1 = Where(mass);
			print_mass(mass1); 
			  break;
		case 5: 
			printf("Write the size of the NEW array  ");
			scanf_s("%d", &array_size2);
			mass2 = create_mass(array_size2, elem_type);
			mass3 = concatination(mass, mass2);
			print_mass(mass3);
			free(mass2);
			free(mass3);
			  break;
		case 6:
			printf("Test int function:\n");
			test_int();
			printf("\nTest double function:\n");
			test_double();
			break;
		case 7:
			printf("Good job");
			break;
		default: printf("ERROR. You need choose an action.");
			break;
		}
		free(mass);
	return 0;
}

int main() {
	interface();
	return 0;
}

