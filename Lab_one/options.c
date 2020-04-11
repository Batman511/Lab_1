#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "options.h"

//создание масива и сохранение в памяти элементов
void create_element_double(Array *mass) {
	//double temp;
	for (int i = 0; i < mass->array_size; i++) {
		printf("Write the element %d: ", i);
		scanf_s("%lf", &(((double*)mass->values)[i])); printf("\n");
		//create_element(mass, i, &temp);
	}
}
void create_element_int(Array *mass) {
	//int temp;
	for (int i = 0; i < mass->array_size; i++) {
		printf("Write the element %d: ", i);
		scanf_s("%d", &(((int*)mass->values)[i])); printf("\n");
		//create_element(mass, i, &temp);
	}
}
Array *create_mass(int array_size, int elem_type) {
	//int temp;
	Array *mass = (void*)malloc(sizeof(Array));
	mass->array_size = array_size;
	mass->elem_type = elem_type;                                   
	switch (elem_type)
	{
	case sizeof(int):
		mass->values = malloc(array_size * sizeof(int));
		create_element_int(mass);
		break;
	case sizeof(double):
		mass->values = malloc(array_size * sizeof(double));
		create_element_double(mass);
		break;
	default:
		break;
	}
	return mass;
}

// функция выбора типа элемента и создание массива
int type_of_element() {
	printf("Choose type of the array:\n1. int\n2. double\n");
	int type;
	do {
		scanf_s("%d", &type); printf("\n");
		if ((type != 1) && (type != 2))
		{
			printf("You must choose 1 or 2\n");
		}
	} while ((type != 1) && (type != 2));

	int element_type;
	if (type == 1) element_type = sizeof(int);
	else if (type == 2) element_type = sizeof(double);

	return element_type;
}

//вывод массива
void print_array_int(Array *mass) {
	for (int i = 0; i < mass->array_size; ++i)
	{
		printf("Element[%d] = %d\n", i, (((int*)mass->values)[i])); //*((int*)mass->values + i));
	}
	printf("\n");
}
void print_array_double(Array *mass) {
	for (int i = 0; i < mass->array_size; ++i)
	{
		printf("Element[%d] = %lf\n", i, (((double*)mass->values)[i])); // *((double*)mass->values + i));
	}
	printf("\n");
}
void print_mass(Array *mass) {
	switch (mass->elem_type)
	{
	case sizeof(int):
		print_array_int(mass);
		break;
	case sizeof(double):
		print_array_double(mass);
		break;
	default:
		break;
	}
}

//сортировка
void sort_bubble_int(Array *mass) {
	int temp;
	for (int i = 0; i < mass->array_size; i++) {
		for (int j = 0; j < mass->array_size - i - 1; j++) {
			if (*((int*)mass->values + j) < *((int*)mass->values + j + 1)) {
				temp = *((int*)mass->values + j);
				*((int*)mass->values + j) = *((int*)mass->values + j + 1);
				*((int*)mass->values + j + 1) = temp;
			}
		}
	}
}
void sort_bubble_double (Array *mass) {
	double temp;
	for (size_t i = 0; i < mass->array_size; i++) {
		for (size_t j = 0; j < mass->array_size - i - 1; j++) {
			if (*((double*)mass->values + j) < *((double*)mass->values + j + 1)) {
				temp = *((double*)mass->values + j);
				*((double*)mass->values + j) = *((double*)mass->values + j + 1);
				*((double*)mass->values + j + 1) = temp;
			}
		}
	}
}
void sort_mass(Array *mass) {
	switch (mass->elem_type)
	{case sizeof(int):
		sort_bubble_int(mass);
		break;
	case sizeof(double):
		sort_bubble_double(mass);
		break;
	default:
		break;
	}
}

//слияние массивов
Array *create_empty_array(int array_size,int elem_type) {
	Array *mass = (void*)malloc(sizeof(Array));
	mass->array_size = array_size;
	mass->elem_type = elem_type;                              
	mass->values = (void*)malloc(array_size * elem_type);
	for (int i = 0; i < array_size; i++) {
		void* p = (char*)mass->values + mass->elem_type * i; //выделение памяти под элемент
	}
	return mass;
}
Array *concatination_int(Array *mass, Array *mass2) {
	Array *mass3 = create_empty_array((mass->array_size) + (mass2->array_size), sizeof(int));
	for (size_t i = 0; i < mass->array_size; i++) {
		*((int*)mass3->values + i) = *((int*)mass->values + i);
	}
	for (size_t i = 0; i < mass2->array_size; i++) {
		*((int*)mass3->values + mass->array_size + i) = *((int*)mass2->values + i);
	}
	return mass3;
}
Array *concatination_double(Array* mass, Array* mass2) {
	Array* mass3 = create_empty_array((mass->array_size) + (mass2->array_size), sizeof(double));
	for (size_t i = 0; i < mass->array_size; i++) {
		*((double*)mass3->values + i) = *((double*)mass->values + i);
	}
	for (size_t i = 0; i < mass2->array_size; i++) {
		*((double*)mass3->values + mass->array_size + i) = *((double*)mass2->values + i);
	}
	return mass3;
}
Array *concatination(Array *mass,Array *mass2) {
	if ((mass->elem_type) == (mass2->elem_type)) {
		Array* mass3;
		//Array* mass3 = (void*)malloc(sizeof(Array));
		//Array* mass3 = create_empty_array((mass2->array_size) + (mass->array_size), mass->elem_type);
		switch (mass->elem_type)
		{
		case sizeof(int):
			mass3 = concatination_int(mass,mass2);
			return mass3;
			break;
		case sizeof(double):
			mass3 = concatination_double(mass, mass2);
			return mass3;
			break;
		default:
			break;
		}
		
	}
	else printf("DIFFERENT TYPES OF THE ARRAYS");
}

//функция map
int multiplication_int(int x) {
	x = x * 2;
	return x;
}
double multiplication_double(double x) {
	x = x * 2;
	return x;
}
int abs_int(int x) {
	if (x < 0) { x = abs(x); }
	return x;
}
double abs_double(double x) {
	if (x < 0) { x = labs(x) - (x-(int)x); }
	return x;
}
void map_int(Array *mass,int(*f)(int)) { //вставляем функцию типа int
	for (int i = 0; i < mass->array_size; i++) {
		*((int*)mass->values + i) = f(*((int*)mass->values + i));
	}
}
void map_double(Array* mass, double(*f)(double)) { //вставляем функцию типа double
	for (size_t i = 0; i < mass->array_size; i++) {
		*((double*)mass->values + i) = f(*((double*)mass->values + i));
	}
}
void map(Array *mass) {
	int temp;
	do {
		printf("Choose an array operation: 1 - multiplication x*2, 2 - absolute values |x|\n");
		scanf_s("%d", &temp);
		if ((temp != 1) && (temp != 2))
		{
			printf("You must choose 1 or 2 \n");
		}
	} while ((temp != 1) && (temp != 2));

	if (mass->elem_type == sizeof(int)) {
		if (temp == 1) {
			map_int(mass, multiplication_int);
		}
		else {
			map_int(mass,abs_int);
		}
	}
	else {
		if (temp == 1) {
			map_double(mass, multiplication_double);
		}
		else {
			map_double(mass,abs_double);
		}
	}
}

//функция where
bool int_even(int x) {
	if (abs(x) % 2 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
bool int_odd(int x) {
	if (abs(x) % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
bool double_even(double x) {
	if (((x - (double)((int)x))) == 0 && abs((int)x) % 2 == 0)
	{
	return 1;
	}
	else {
		return 0;
	}
}
bool double_odd(double x) {
	if (((x - (double)((int)x))) == 0 && abs((int)x) % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
Array *Where_int(Array *mass, int(*f)(int)) {
	int temp = 0, S = 0;
	for (int i = 0; i < mass->array_size; i++)
	{
		if (f(((int*)mass->values)[i]) == 1) //(f(*((int*)mass->values + i)) == 1)
		{
			temp++;
		}
	}
	if (temp==0) printf("Array hasn't elements for this situation\n");
	Array *mass1 = create_empty_array(temp, sizeof(int));
	for (int i = 0; i < mass->array_size; i++)
	{
		if (f(((int*)mass->values)[i]) == 1)
		{
			*((int*)mass1->values + S) = *((int*)mass->values + i); //(((int*)mass1->values)[S]) = (((int*)mass1->values)[i]);
			S++;
		}
	}
	return mass1;
}
Array *Where_double(Array *mass, int(*f)(double)) {
	int temp = 0, S = 0;
	for (size_t i = 0; i < mass->array_size; i++)
	{
		if (f(((double*)mass->values)[i]) == 1)
		{
			temp++;
		}
	}
	if (temp == 0) {
		printf("Array hasn't int elements for this situation\n");
	}
	Array* mass1 = create_empty_array(temp, sizeof(double));
	for (int i = 0; i < mass->array_size; i++)
	{
		if (f(((double*)mass->values)[i]) == 1)
		{
			*((double*)mass1->values + S) = *((double*)mass->values + i);
			S++;
		}
	}
	return mass1;
}
Array *Where(Array *mass) {
	int temp = 0;
	//Array *mass1 = (void*)malloc(sizeof(Array));
	printf("Choose an array operation: 1 - print even elements, 2 - print odd elements\n");
	do {
		scanf_s("%d", &temp);
		if ((temp != 1) && (temp != 2))
		{
			printf("You must choose 1 or 2 \n");
		}
	} while ((temp != 1) && (temp != 2));
	
	switch (mass->elem_type)
	{
	case sizeof(int):
		if (temp == 1) {
			Where_int(mass,int_even);
		}
		else {
			Where_int(mass, int_odd);
		}
		break;
	case sizeof(double):
		if (temp == 1) {
			Where_double(mass, double_even);
		}
		else {
			Where_double(mass, double_odd);
		}
		break;
	default:
		break;
	}
	//return mass1;
}
