//迭代的解法
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

const int kSizeN = 5;
const int kSizeM = 3;

void PrintKCombine(int index_M, int index_N)
{
	if (index_M < 0 || index_N < 0 || index_M > index_N)
		return;

	int *array = new int[index_M];
	for (int i = 1; i <= index_M; i++) {
		array[i - 1] = i;
	}

	int index = index_M - 1;
	while (array[0] != index_N - index_M + 1) {
		if (array[index_M - 1] == index_N) {
			--index;
		} else {
			index = index_M - 1;
		}

		array[index]++;
		for (int i = index + 1; i < index_M; i++) {
			array[i] = array[i - 1] + 1;
		}

		copy(array, array + index_M, ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	delete[] array;
}

void main()
{
	PrintKCombine(3, 5);
}

