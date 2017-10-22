//
//  FunctionPointerModelViewController.c
//  FunctionPointer
//
//  Created by Mewlan Musajan on 10/22/17.
//  Copyright (c) 2017 Mewlan Musajan. All rights reserved.
//

#include <stdio.h>

int Flag;
int Result;

int max(int *a, int *b);
int min(int *a, int *b);
void errorOutPutView();
void selectionInPutController();


int main(int argc, char const *argv[])
{
	model();
	return 0;
}

void model()
{
	
	int (*funcPtr)(int, int);
	int a, b;
	view(funcPtr, &a, &b);
}

void view(int (*funcPtr)(int, int), int *a, int *b)
{
	printf("enter two numbers:\n");
	numberInPutController(a, b);
	printf("max or min?(1/2)\n");
	selectionInPutController();
	controller(funcPtr, a, b);
	printf("%d\n", Result);
}

void errorOutPutView()
{
	printf("\'%d\' is not a command.\n", Flag);
}

void controller(int (*funcPtr)(int, int), int *a, int *b)
{
	if (Flag == 1)
	{
		funcPtr = max;
		Result = (*funcPtr)(a, b);
	} else {
		funcPtr = min;
		Result = (*funcPtr)(a, b);
	}
}

void numberInPutController(int *a, int *b)
{
	for (int i = 0; i < 2; ++i)
	{
		if (i)
		{
			scanf("%d", b);
		} else {
			scanf("%d", a);
		}
		
	}
}

void selectionInPutController()
{
	scanf("%d", &Flag);
	if (Flag != 1 && Flag != 2)
	{
		errorOutPutView();
		selectionInPutController();
	}
}

int max(int *a, int *b)
{
	int c;
	if (*a > *b)
	{
		c = *a;
	} else {
		c = *b;
	}
	return(c);
}

int min(int *a, int *b)
{
	int c;
	if (*a < *b)
	{
		c = *a;
	} else {
		c = *b;
	}
	return(c);
}





