#include <iostream>

using namespace std;

int array[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
const int kArraySize = sizeof array / sizeof *array;

//get longest length, as what the book says
int GetLongestLength(int *array, int kArraySize)
{
	if (array == NULL || kArraySize < 0)
	{
		return 0;
	}

	int length = 1;
	for (int i = 1; i < kArraySize; i++)
	{
		if (array[i] == array[i - length])
		{
			length++;
		}
	}

	return length;
}

//the algorithm above has many unlessary comparision
int GetLongestLength2(int *array, int size)
{
	if (array == NULL || size < 0)
	{
		return 0;
	}

	int length = 1;
	int index = 1;
	while (index < size)
	{
		if (array[index] == array[index - length])
		{
			length++;
			index++;
		}
		else
		{
			index += length;
		}
	}

	return length;
}

int main()
{
	int longest_length = GetLongestLength2(array, kArraySize);
	cout << "longest_length = " << longest_length << endl;

	return 0;
}

