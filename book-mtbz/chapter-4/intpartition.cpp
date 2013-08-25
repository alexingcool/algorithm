#include <iostream>

using namespace std;

#define MAXSIZE 20

void Display(int *array, int *mult, int index)
{
	if (array == NULL || mult == NULL || index < 0)
	{
		return;
	}

	for (int i = 0; i <= index; i++)
	{
		for (int j = 0; j < mult[i]; j++)
		{
			cout << array[i] << " ";
		}
	}
	cout << endl;
}

int GetPartition(int number)
{
	if (number < 0)
	{
		cerr << "number must be greater than 0" << endl;
		return -1;
	}

	int array[MAXSIZE];
	int mults[MAXSIZE];
	int index = 0;
	array[index] = number;
	mults[index] = 1;

	Display(array, mults, index);

	do
	{
		int sum = array[index] == 1 ? mults[index--] + 1 : 1;
		int value = array[index] - 1;
		if (mults[index] > 1)
			mults[index++]--;
		array[index] = value;
		mults[index] = sum / value + 1;
		int remainder = sum % value;
		if (remainder != 0)
		{
			array[++index] = remainder;
			mults[index] = 1;
		}

		Display(array, mults, index);
	} while (mults[index] != number);

	return 0;
}

int main()
{
	GetPartition(7);
	return 0;
}
