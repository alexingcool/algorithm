#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>

using namespace std;

#define INF 65535

int array[] = {5, 4, 1, 2, 3, 9, 8, 7, 6};
const int size = sizeof array / sizeof *array;

void quickSort(int *array, int size)
{
	if (array == NULL || size <= 0)
		return;

	stack<int> istack;
	for (int i = 0; i < size; i++)
	{
		while (array[i] != INF)
		{
			int &key = array[i];
			int split = i;
			int j = split + 1;
			while (j < size && array[j] != INF)
			{
				if (array[j] < key)
				{
					split++;
					swap(array[j], array[split]);
				}
				j++;
			}
			swap(key, array[split]);
			istack.push(array[split]);
			array[split] = INF;
		}
		array[i] = istack.top();
		istack.pop();
	}
}

int partition(int *array, int start, int last)
{
	if (array == NULL || start < 0 || last < 0 || start > last)
		return -1;

	int i = start - 1;
	int j = start;
	int &key = array[last];
	while (j < last)
	{
		if (array[j] < key)
		{
			i++;
			swap(array[i], array[j]);
		}
		j++;
	}
	swap(array[++i], key);
	return i;
}

void quickSort(int *array, int start, int last)
{
	if (array == NULL || start < 0 || last < 0 || start > last)
		return;

	int splitIndex = partition(array, start, last);
	quickSort(array, start, splitIndex - 1);
	quickSort(array, splitIndex + 1, last);
}

void main()
{
	quickSort(array, 0, size - 1);
	copy(array, array + size, ostream_iterator<int>(cout, " "));
	cout << endl;
}
