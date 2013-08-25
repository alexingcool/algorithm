#include <iostream>

using namespace std;

bool Check(int *array, int index)
{
	if (array == NULL || index < 0)
		return false;

	int length = (index + 1) >> 1;
	for (int i = 1; i <= length; i++)
	{
		int pos = 0;
		while (pos < i && array[index - i - pos] == array[index - pos])
			pos++;

		if (pos == i)
			return false;
	}

	return true;
}

void PrintCombine(int number, int length)
{
	if (number < 0 || length <= 0)
		return;

	//length larger than number, so array size length is enough
	int *array = new int[length];
	array[0] = 1;
	array[1] = 2;
	int index = 1;

	while (index >= 0)
	{
		if (Check(array, index) == true)
		{
			if (index == length - 1)
			{
				for (int i = 0; i <= index; i++)
					cout << array[i] << " ";
				cout << endl;

				while (index >= 0 && array[index] == number)
				{
					index--;
				}
				if (index < 0)
				{
					break;
				}
				array[index] = array[index] + 1;
			}
			else
			{
				array[++index] = 1;
			}
		}
		else
		{
			while (index >= 0 && array[index] == number)
			{
				index--;
			}
			if (index < 0)
			{
				break;
			}
			array[index] = array[index] + 1;
		}
	}

	delete[] array;
}

int main()
{
	PrintCombine(3, 5);

	return 0;
}
