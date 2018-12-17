#include "pch.h"
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <time.h>

int Cheking(int number)
{
	char chek = '\0';
	while (scanf_s("%d%c", &number, &chek, 1) != 2 || chek != '\n' || (number < 1))
	{	
		if (number < 1)
		{
			printf("Ошибка, введете положительное число: \n");
			rewind(stdin);
		}
		else
		{
			printf("Ошибка, введете корректное число: \n");
		}
	}
	return(number);
}



int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int Size = 0, SelectMenu = 0, SecondMenu = 0, Processing = 0, Exit = 0;
	char chek = '\0';
	bool menu = false;
	printf ("Введите размер массива : ");
	while (scanf_s("%d%c", &Size, &chek, 1) != 2 || chek != '\n' || (Size < 1)) //cheking
	{
		while (getchar() != '\n');
		printf("Ошибка, введете положительное число: \n");
	}
	int* myArray = new int[Size](); // указатель на массив н-элементов типа инт
	for (int i = 0; i < Size; i= i+1)
	{
		myArray[i] = 0;
	}
	while (menu != true)
	{
		system("cls");
		printf("Добро пожаловать в меню. Что вы хотите сделать?\n 1. Ввод элементов массива\n 2. Обработка массива\n 3. Вывод массива на экран\n 4. Выход\n");
		while (scanf_s("%d%c", &SelectMenu, &chek, 1) != 2 || chek != '\n' || SelectMenu > 4 || SelectMenu < 1) //cheking
		{
			while (getchar() != '\n');
			printf("Ошибка, введете число от 1 до 4: \n");
		}
		system("cls");
		if (SelectMenu == 1) //Begin 1
		{
			printf("Ввод элементов массива: \n 1.Вручную \n 2.Случайными числами \n");
			while (scanf_s("%d%c", &SecondMenu, &chek, 1) != 2 || chek != '\n' || SecondMenu > 2 || SecondMenu < 1) //cheking
			{
				while (getchar() != '\n');
				printf("Ошибка, введете число от 1 до 2: \n");
			}
			if (SecondMenu == 1)
			{
				system("cls");
				for (int i = 0; i < Size; i = i + 1)
				{
					printf("Введите %d элемент ", i + 1);
					while (scanf_s("%d%c", &myArray[i], &chek, 1) != 2 || chek != '\n') //cheking
					{
						while (getchar() != '\n');
						printf("Ошибка, введете положительное число: \n");
					}
				}
			}
			else if (SecondMenu == 2)
			{
				system("cls");
				for (int i = 0; i < Size; i++)
				{
					myArray[i] = rand();
				}
			}
		} // End 1

		if (SelectMenu == 2) //Begin 2
		{
			system("cls");
			int Sum = 0, Amount = 0, Max = -1, Average = 0;
			for (int i = 0; i < Size; i++)	//Общая сумма и кол-во чисел
			{
				if ( (i+1) % 2 != 0)
				{
					Sum = Sum + myArray[i];
					Amount = Amount + 1;
				}
			}
			Average = Sum / Amount;
			for (int i = 0; i < Size; i++) //Нахождение максимума 
			{
				if (myArray[i] > Max)
				{
					Max = myArray[i];
				}
			}
			for (int i = 0; i < Size; i++) //Обработка 
			{
				if (myArray[i] == Max)
				{
					myArray[i] = Average;
				}
			}

		}

		if (SelectMenu == 3) //Begin 3
		{
			system("cls");
			for (int i = 0; i < Size; i++)
			{
				printf("%d/n/t", myArray[i]);
			}
			printf("\n");
			system("pause");
		}
		if (SelectMenu == 4) //Begin 4
		{
			system("cls");
			printf("Вы хотите выйти? \n 1.Да \n 2.Нет \n");
			while (scanf_s("%d%c", &Exit, &chek, 1) != 2 || chek != '\n' || Exit > 2 || Exit < 1) //cheking
			{
				while (getchar() != '\n');
				printf("Ошибка, введете число от 1 до 2: \n");
			}
			if (Exit == 1)
			{
				menu = true;
			}
		}
	}
	delete[] myArray;
	return 0;
}
