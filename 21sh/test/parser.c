#include <stdio.h>
#include <string.h>
// Recusive decent parser for
// E -> TE'
// E'-> +TE' | NULL
// T -> FT'
// T' -> *FT' | NULL
// F -> (E) | id

void E();
void T();
void F();
void Edes();
void Tdes();
char input[100];
int i, error;

int main()
{
	while (1)
	{
		i = 0;
		printf("Enter input\n");
		gets(input);
		E();
		if (i == strlen(input) && error==0)
			printf("String is accepted\n");
		else
			printf("Fail\n");
	}
	return (0);
}

void E()
{
	T();
	Edes();
}

void T()
{
	F();
	Tdes();
}

void Edes()
{
	if (input[i] == '+')
	{
		i++;
		T();
		Edes();
	}
}

void Tdes()
{
	if (input[i] == '*')
	{
		i++;
		F();
		Tdes();
	}
}

void F()
{
	if (input[i] == 'a')
		i++;
	else if (input[i] == '(')
	{
		i++;
		E();
		if (input[i] == ')')
			i++;
		else
			error = 1;
	}
	else
		error = 1;
}