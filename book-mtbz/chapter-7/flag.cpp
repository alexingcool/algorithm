#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

char array[] = {'R', 'B', 'W', 'W', 'R', 'B', 'W', 'R', 'B', 'W', 'R', 'W'};
const int size = sizeof array / sizeof *array;

void sortColor(char *array, int size)
{
	if (array == NULL || size <= 0)
		return;

	int blueIndex = 0;
	int whiteIndex = 0;
	int redIndex = size - 1;

	while (whiteIndex < redIndex)
	{
		if (array[whiteIndex] == 'W')
			whiteIndex++;
		else if (array[whiteIndex] == 'B')
		{
			swap(array[blueIndex], array[whiteIndex]);
			blueIndex++;
			whiteIndex++;
		}
		else
		{
			while (whiteIndex < redIndex && array[redIndex] == 'R')
				redIndex--;
			swap(array[whiteIndex], array[redIndex]);
		}
	}
}

void main()
{
	sortColor(array, size);
	copy(array, array + size, ostream_iterator<char>(cout, " "));
	cout << endl;
}
