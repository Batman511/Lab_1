#pragma once
#include <stdbool.h>
//typedef enum {DOUBLE,INT} Atype;
typedef struct {
	int elem_type;
	void* values;
	int array_size;
} Array;

void create_element_double(Array* mass);
void create_element_int(Array* mass);
Array* create_mass(int array_size, int elem_type);
int type_of_element();
void print_array_int(Array* mass);
void print_array_double(Array* mass);
void print_mass(Array* mass);
void sort_bubble_int(Array* mass);
void sort_bubble_double(Array* mass);
void sort_mass(Array* mass);
Array* create_empty_array(int array_size, int elem_type);
Array* concatination_int(Array* mass, Array* mass2);
Array* concatination_double(Array* mass, Array* mass2);
Array* concatination(Array* mass, Array* mass2);
int multiplication_int(int x);
double multiplication_double(double x);
int abs_int(int x);
double abs_double(double x);
void map_int(Array* mass, int(*f)(int));
void map_double(Array* mass, double(*f)(double));
void map(Array* mass);
bool int_even(int x);
bool int_odd(int x);
bool double_even(double x);
bool double_odd(double x);
Array* Where_int(Array* mass, int(*f)(int));
Array* Where_double(Array* mass, int(*f)(double));
Array* Where(Array* mass);
int interface();


