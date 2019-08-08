#pragma once
#pragma warning(disable: 4996)
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 매크로 상수
#define STR_SIZE 30

// Structures
typedef struct ID
{
	char str[STR_SIZE + 1];
	int length;
}ID;

typedef struct ID_DB
{
	ID* id_list;
	int id_count;
	int list_length;
}ID_DB;

/*Functions*/
void Init(ID_DB* list, int size);
int Is_Full(ID_DB* list);
int Is_ID_Duplicated(ID_DB* list, const char* str);
int Validate_ID(const char* str, int size);
int Get_ID(char* str);
int Input_ID(ID_DB* list);
int Compare_ID(const void* v1, const void* v2);
void View_ID(ID_DB* list);

//Test the system
void Test_ID_SYS();