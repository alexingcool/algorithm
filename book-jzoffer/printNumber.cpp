#include <iostream>

using namespace std;

//有bug的print函数
/*
void print(const char *str)
{
    if (str == NULL)
		return;

	const int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '0')
			continue;
		cout << str[i];
	}
	cout << endl;
}
*/

void print(const char *str)
{
	if (str == NULL)
		return;

	const int size = strlen(str);
	int index = 0;
	while (index < size && str[index] == '0')
		index++;

	while (index < size)
		cout << str[index++];
	cout << endl;
}

bool genNumbers(char *array, int size)
{
	bool isFinished = false;
	if (array == NULL || size <= 0)
		return isFinished;

	int carry = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int sum = array[i] - '0' + carry;
		if (i == size - 1)
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
			{
				isFinished = true;
				break;
			}
			else
			{
				carry = 1;
				array[i] = sum - 10 + '0';
			}
		}
		else
		{
			array[i] = sum + '0';
			break;
		}
	}

	return isFinished;
}

void printNumbers(int number)
{
	if (number <= 0)
		return;

	char *array = new char[number + 1];
	array[number] = '\0';
	for (int i = 0; i < number; i++)
	{
		array[i] = '0';
	}

	while (genNumbers(array, number) == false)
		print(array);
}

void recursivePrint(char *array, int index)
{
	if (array == NULL || index < 0)
		return;

	if (index == strlen(array))
	{
		print(array);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		array[index] = i + '0';
		recursivePrint(array, index + 1);
	}
}

void printNumbers2(int number)
{
	if (number <= 0)
		return;

	char *array = new char[number + 1];
	array[number] = '\0';
	for (int i = 0; i < number; i++)
	{
		array[i] = '0';
	}

	recursivePrint(array, 0);
}

void main()
{
	printNumbers2(3);
}
