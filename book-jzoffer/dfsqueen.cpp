#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int isValid(int *array, int size, int index)
{
	if (array == NULL || size <= 0)
		return -1;

	for (int i = 0; i < index; i++)
	{
		if (abs(i - index) == abs(array[i] - array[index]) || array[i] == array[index])
			return 0;
	}

	return 1;
}

int DFSQueen(int *array, int size, int index)
{
	if (array == NULL || size <= 0)
		return -1;

	int count = 0;

	if (index == size)
	{
		copy(array, array + size, ostream_iterator<int>(cout, " "));
		cout << endl;
		count++;
		return count;
	}
	for (int i = 0; i < 8; i++)
	{
		array[index] = i;
		if (isValid(array, size, index) == 1)
			count += DFSQueen(array, size, index + 1);
	}

	return count;
}

int main()
{
	int array[8];
	int count = DFSQueen(array, 8, 0);
	cout << "count = " << count << endl;
	return 0;
}
