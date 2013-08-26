#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int getNEmpress(int *array, int index, int size)
{
	if (array == NULL || size <= 0)
		return -1;

	int count = 0;
	if (index == size)
	{
		bool result = true;
		for (int i = 0; i < 7; i++)
		{
			for (int j = i + 1; j < 8; j++)
			{
				if (abs(i - j) == abs(array[i] - array[j]))
					result = false;
			}
		}
		if (result == true)
			count++;
		return count;
	}

	for (int i = index; i < size; i++)
	{
		swap(array[i], array[index]);
		count += getNEmpress(array, index + 1, size);
		swap(array[i], array[index]);
	}

	return count;
}

int main()
{
	int array[8];
	for (int i = 0; i < 8; i++)
		array[i] = i;

	int count = 0;
	count = getNEmpress(array, 0, 8);
	cout << "count =  " << count << endl;

	return 0;
}
