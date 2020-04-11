#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "options.h"
#include "Test.h"

bool Check(Array *mass1,Array *mass2) {
	if (mass1->elem_type != mass2->elem_type) return false;
	if (mass1->array_size != mass2->array_size) return false;

	if (mass1->elem_type == sizeof(int)) {
		for (int i = 0; i < mass1->array_size; i++) {
			if (((int*)mass1->values)[i] != ((int*)mass2->values)[i]) return false;
		}
	}
	else if (mass1->elem_type == sizeof(double)) {
		for (int i = 0; i < mass1->array_size; i++) {
			if (((double*)mass1->values)[i] != ((double*)mass2->values)[i]) return false;
		}
	}
	return true;
}

void test_int() {
	Array *test_mass1 = create_empty_array(5, sizeof(int));
	Array *test_mass2 = create_empty_array(5, sizeof(int));
	Array *test_mass2_where1 = create_empty_array(3, sizeof(int));
	Array *test_mass2_where2 = create_empty_array(2, sizeof(int));
	Array* test_mass3_where1; // = create_empty_array(3, sizeof(int));
	Array* test_mass3_where2;
	
	//сортировка
	((int*)test_mass1->values)[0] = 2;
	((int*)test_mass1->values)[1] = -4;
	((int*)test_mass1->values)[2] = 11;
	((int*)test_mass1->values)[3] = 71;
	((int*)test_mass1->values)[4] = -122;
	sort_mass(test_mass1);
	((int*)test_mass2->values)[0] = 71;
	((int*)test_mass2->values)[1] = 11;
	((int*)test_mass2->values)[2] = 2;
	((int*)test_mass2->values)[3] = -4;
	((int*)test_mass2->values)[4] = -122;

	if (Check(test_mass1, test_mass2)) {
		printf(" Test sorting : success\n ");
	}
	else {
		printf(" Test sorting : fail\n ");
	}

	//map
	((int*)test_mass1->values)[0] = 2;
	((int*)test_mass1->values)[1] = -4;
	((int*)test_mass1->values)[2] = 11;
	((int*)test_mass1->values)[3] = 71;
	((int*)test_mass1->values)[4] = -122;
	map_int(test_mass1, multiplication_int);
	((int*)test_mass2->values)[0] = 4;
	((int*)test_mass2->values)[1] = -8;
	((int*)test_mass2->values)[2] = 22;
	((int*)test_mass2->values)[3] = 142;
	((int*)test_mass2->values)[4] = -244;
	if (Check(test_mass1, test_mass2)) {
		printf("Test map (multiplication) : success\n ");
	}
	else {
		printf("Test map (multiplication) : fail\n ");
	}

	map_int(test_mass1, abs_int);
	((int*)test_mass2->values)[0] = 4;
	((int*)test_mass2->values)[1] = 8;
	((int*)test_mass2->values)[2] = 22;
	((int*)test_mass2->values)[3] = 142;
	((int*)test_mass2->values)[4] = 244;

	if (Check(test_mass1, test_mass2)) {
		printf("Test map (abs) : success\n ");
	}
	else {
		printf("Test map (abs) : fail\n ");
	}
	free(test_mass2);

//where 
	((int*)test_mass1->values)[0] = 2;
	((int*)test_mass1->values)[1] = -4;
	((int*)test_mass1->values)[2] = 11;
	((int*)test_mass1->values)[3] = 71;
	((int*)test_mass1->values)[4] = -122;
	
	((int*)test_mass2_where1->values)[0] = 2;
	((int*)test_mass2_where1->values)[1] = -4;
	((int*)test_mass2_where1->values)[2] = -122;

	test_mass3_where1 = Where_int(test_mass1, int_even);
	if (Check(test_mass3_where1, test_mass2_where1)) {
		printf("Test where (even) : success\n ");
	}
	else {
		printf("Test where (even) : fail\n ");
	}
	free(test_mass3_where1);
	
	test_mass3_where2 = Where_int(test_mass1, int_odd);
	((int*)test_mass2_where2->values)[0] = 11;
	((int*)test_mass2_where2->values)[1] = 71;

	if (Check(test_mass3_where2, test_mass2_where2)) {
		printf("Test where (odd) : success\n ");
	}
	else {
		printf("Test where (odd) : fail\n ");
	}
	free(test_mass3_where2);
	free(test_mass2_where1);
	free(test_mass2_where2);


//concatination
	((int*)test_mass1->values)[0] = 2;
	((int*)test_mass1->values)[1] = -4;
	((int*)test_mass1->values)[2] = 11;
	((int*)test_mass1->values)[3] = 71;
	((int*)test_mass1->values)[4] = -122;

	Array* test_mass3_1 = create_empty_array(3, sizeof(int));
	((int*)test_mass3_1->values)[0] = 7;
	((int*)test_mass3_1->values)[1] = -8;
	((int*)test_mass3_1->values)[2] = 9;

	Array* test_mass3_3;

	Array* test_mass3_2 = create_empty_array(8, sizeof(int));
	((int*)test_mass3_2->values)[0] = 2;
	((int*)test_mass3_2->values)[1] = -4;
	((int*)test_mass3_2->values)[2] =11;
	((int*)test_mass3_2->values)[3] = 71;
	((int*)test_mass3_2->values)[4] = -122;
	((int*)test_mass3_2->values)[5] = 7;
	((int*)test_mass3_2->values)[6] = -8;
	((int*)test_mass3_2->values)[7] = 9;

	test_mass3_3 = concatination_int(test_mass1,test_mass3_1);
	if (Check(test_mass3_3, test_mass3_2)) {
		printf("Test concatination : success\n ");
	}
	else {
		printf("Test concatination : fail\n ");
	}
	free(test_mass3_3);
	free(test_mass3_1);
	free(test_mass3_2);
	free(test_mass1);
}

void test_double() {
	Array* test_mass1 = create_empty_array(5, sizeof(double));
	Array* test_mass2 = create_empty_array(5, sizeof(double));
	Array* test_mass2_where1 = create_empty_array(1, sizeof(double));
	Array* test_mass2_where2 = create_empty_array(1, sizeof(double));
	Array* test_mass3_where1;
	Array* test_mass3_where2;

	//сортировка
	((double*)test_mass1->values)[0] = -11;
	((double*)test_mass1->values)[1] = -4.4;
	((double*)test_mass1->values)[2] = 5.25;
	((double*)test_mass1->values)[3] = 3.45;
	((double*)test_mass1->values)[4] = 2;
	sort_mass(test_mass1);
	((double*)test_mass2->values)[0] = 5.25;
	((double*)test_mass2->values)[1] = 3.45;
	((double*)test_mass2->values)[2] = 2;
	((double*)test_mass2->values)[3] = -4.4;
	((double*)test_mass2->values)[4] = -11;

	if (Check(test_mass1, test_mass2)) {
		printf(" Test sorting : success\n ");
	}
	else {
		printf(" Test sorting : fail\n ");
	}
	
	//map
	((double*)test_mass1->values)[0] = -11;
	((double*)test_mass1->values)[1] = -4.4;
	((double*)test_mass1->values)[2] = 5.25;
	((double*)test_mass1->values)[3] = 3.45;
	((double*)test_mass1->values)[4] = 2;
	map_double(test_mass1, multiplication_double);
	((double*)test_mass2->values)[0] = -22;
	((double*)test_mass2->values)[1] = -8.8;
	((double*)test_mass2->values)[2] = 10.5;
	((double*)test_mass2->values)[3] = 6.9;
	((double*)test_mass2->values)[4] = 4;
	if (Check(test_mass1, test_mass2)) {
		printf("Test map (multiplication) : success\n ");
	}
	else {
		printf("Test map (multiplication) : fail\n ");
	}

	map_double(test_mass1, abs_double);
	((double*)test_mass2->values)[0] = 22;
	((double*)test_mass2->values)[1] = 8.8;
	((double*)test_mass2->values)[2] = 10.5;
	((double*)test_mass2->values)[3] = 6.9;
	((double*)test_mass2->values)[4] = 4;

	if (Check(test_mass1, test_mass2)) {
		printf("Test map (abs) : success\n ");
	}
	else {
		printf("Test map (abs) : fail\n ");
	}
	free(test_mass2);
	
	//where 
	((double*)test_mass1->values)[0] = -11;
	((double*)test_mass1->values)[1] = -4.4;
	((double*)test_mass1->values)[2] = 5.25;
	((double*)test_mass1->values)[3] = 3.45;
	((double*)test_mass1->values)[4] = 2;

	((double*)test_mass2_where1->values)[0] = 2;

	test_mass3_where1 = Where_double(test_mass1, double_even);
	if (Check(test_mass3_where1, test_mass2_where1)) {
		printf("Test where (even) : success\n ");
	}
	else {
		printf("Test where (even) : fail\n ");
	}
	free(test_mass3_where1);

	test_mass3_where2 = Where_double(test_mass1, double_odd);
	((double*)test_mass2_where2->values)[0] = -11;

	if (Check(test_mass3_where2, test_mass2_where2)) {
		printf("Test where (odd) : success\n ");
	}
	else {
		printf("Test where (odd) : fail\n ");
	}
	free(test_mass3_where2);
	free(test_mass2_where1);
	free(test_mass2_where2);

	
	//concatination
	((double*)test_mass1->values)[0] = -11;
	((double*)test_mass1->values)[1] = -4.4;
	((double*)test_mass1->values)[2] = 5.25;
	((double*)test_mass1->values)[3] = 3.45;
	((double*)test_mass1->values)[4] = 2;

	Array* test_mass3_1 = create_empty_array(3, sizeof(double));
	((double*)test_mass3_1->values)[0] = 14.23;
	((double*)test_mass3_1->values)[1] = -8;
	((double*)test_mass3_1->values)[2] = -1.23;

	Array* test_mass3_3;

	Array* test_mass3_2 = create_empty_array(8, sizeof(double));
	((double*)test_mass3_2->values)[0] = -11;
	((double*)test_mass3_2->values)[1] = -4.4;
	((double*)test_mass3_2->values)[2] = 5.25;
	((double*)test_mass3_2->values)[3] = 3.45;
	((double*)test_mass3_2->values)[4] = 2;
	((double*)test_mass3_2->values)[5] = 14.23;
	((double*)test_mass3_2->values)[6] = -8;
	((double*)test_mass3_2->values)[7] = -1.23;

	test_mass3_3 = concatination_double(test_mass1, test_mass3_1);
	if (Check(test_mass3_3, test_mass3_2)) {
		printf("Test concatination : success\n ");
	}
	else {
		printf("Test concatination : fail\n ");
	}
	free(test_mass3_3);
	free(test_mass3_1);
	free(test_mass3_2);
	free(test_mass1);
}





