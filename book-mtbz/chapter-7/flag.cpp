/*
三色旗问题

假设有一个数组，它有n个元素，每一个不外乎是红、白、蓝3中颜色之一的代号，就用R、W、B代表。
这些元素在数组中并没有依同样颜色的元素排在一起的方式来排列，请写一个程序把这个元素排成所有蓝色在前，
接着是白色，最后是红色的排列方式，不过在写程序时要满足下面的条件：

1. 不能用额外的内存，换句话说，只能在数组之内用互换的方式完成

2. 互换两个元素的动作要越少越好

3. 对于每一个元素而言，测试它是红、白还是蓝的工作每种颜色最多只能做一次测试

在这个条件下，写一个最快的程序。

*/
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
