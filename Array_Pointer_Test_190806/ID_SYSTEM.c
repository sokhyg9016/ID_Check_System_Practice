#include "ID_SYSTEM.h"

void Init(ID_DB* list, int size)
{
	list->list_length = 0;
	list->id_count = size;
}

int Is_Full(ID_DB* list)
{
	return (list->list_length == list->id_count);
}

int Get_ID(char* str)
{
	int ch;
	int i;

	i = 0;
	
	printf("���̵� �Է�: ");
	while ((ch = getchar()) != '\n')
	{
		if (i < STR_SIZE)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

int Is_ID_Duplicated(ID_DB* list, const char* str)
{
	int i;

	for (i = 0; i < list->list_length; i++)
	{
		if (!strcmp(str, list->id_list[i].str))
		{
			fprintf(stderr, "�迭�� �ߺ��Ǿ����ϴ�.\n");
			return 0;
		}
	}
	return 1;
}

int Validate_ID(const char* str, int size)
{
	int i;

	//FLAG
	int is_alpha_b = 0;
	int is_alpha_s = 0;
	int is_number = 0;

	if (!isalnum(str[0]))
	{
		fprintf(stderr, "���̵��� ó������ Ư�����ڰ� ���� �� �����ϴ�.\n");
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		if (islower(str[i]))
		{
			is_alpha_s = 1;
		}
		else if (isupper(str[i]))
		{
			is_alpha_b = 1;
		}
		else if (isdigit(str[i]))
		{
			is_number = 1;
		}
	}

	if (is_alpha_b && is_alpha_s && is_number)
	{
		return 1;
	}
	else if (!is_alpha_b || !is_alpha_s)
	{
		fprintf(stderr, "�빮�ڿ� �ҹ��ڰ� ���� 1�� �̻� ���;� �մϴ�.\n");
		return 0;
	}
	else
	{
		fprintf(stderr, "���ڰ� 1�� �̻� ���;� �մϴ�.\n");
		return 0;
	}
}

int Input_ID(ID_DB* list)
{
	char temp[STR_SIZE + 1];
	int current = list->list_length;

	if (Is_Full(list))
	{
		fprintf(stderr,"ID�� ������ �� �ִ� ������ ����á���ϴ�.\n");
		return 0;
	}
	
	while (1)
	{
		Get_ID(temp);
		rewind(stdin);

		if (Is_ID_Duplicated(list, temp) && Validate_ID(temp, strlen(temp)))
		{
			break;
		}
	}
	strcpy(list->id_list[current].str, temp);
	list->id_list->length = strlen(list->id_list[current].str);
	list->list_length++;

	qsort(list->id_list, list->list_length, sizeof(ID), Compare_ID);
	
	return 1;
}

int Compare_ID(const void* v1, const void* v2)
{
	ID* id1 = (ID*)v1;
	ID* id2 = (ID*)v2;
	
	return strcmp(id1->str, id2->str);
}

void View_ID(ID_DB* list)
{
	int i;

	for (i = 0; i < list->list_length; i++)
	{
		printf("[%02d] = %s\n", i, list->id_list[i].str);
	}
	puts("");
}

void Test_ID_SYS()
{
	ID_DB list;
	int command, id_number;

	fputs("INPUT SIZE: ", stdout);
	scanf("%d", &id_number);
	Init(&list, id_number);

	list.id_list = (ID*)malloc(sizeof(ID)* id_number);

	while (1)
	{
		printf("[1]: �Է�, [2]: ���̵� ��� ���, [-999]: clear, [999]: exit\n");
		printf("INPUT: ");

		if (scanf("%d", &command) == 1)
		{
			rewind(stdin);

			if (command == 999)
				break;

			switch (command)
			{
			case 1:
				Input_ID(&list);
				break;
			case 2:
				View_ID(&list);
				break;
			case -999:
				system("cls");
				break;
			default:
				break;
			}
		}
		else
		{
			rewind(stdin);
			printf("�ùٸ� command�� �Է��Ͻʽÿ�.\n");
		}
	}

	free(list.id_list);
}