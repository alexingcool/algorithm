#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int array[] = {10, 1, 5, 3, 2, 4, 8, 9, 6};
const int size = sizeof array / sizeof *array;

void fastInsertSort(int *array, int size)
{
	if (array == NULL || size <= 0)
		return;

	for (int i = 1; i < size; i++)
	{
		int pivot = array[i];
		int pos;
		if (pivot < array[0])
			pos = 0;
		else if (pivot > array[i - 1])
			pos = i;
		else
		{
			int left = 0;
			int right = i - 1;
			while (left != right - 1)
			{
				int mid = (left + right) / 2;
				if (array[mid] < pivot)
					left = mid;
				else if (array[mid] > pivot)
					right = mid;
			}
			pos = left + 1;
		}
		memcpy(&array[pos + 1], &array[pos], (i - pos) * sizeof (int));
		array[pos] = pivot;
	}
}
	
int main()
{
	fastInsertSort(array, size);
	copy(array, array + size, ostream_iterator<int>(cout, " "));

	return 0;
}
