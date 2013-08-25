#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;

int array[] = {5, 4, -8, 6, -9, 1, 2};
const int size = sizeof array / sizeof *array;

stack<int> st;
#define INF 65535

void quickSort(int *array, int size)
{
	if (array == NULL || size <= 0)
		return;

	for (int i = 0; i < size; i++)
	{
		while (array[i] != INF)
		{
			int split = i;
			int j = split + 1;
			int &pivot = array[split];
			while (j < size && array[j] != INF)
			{
				if (array[j] < pivot)
				{
					split++;
					swap(array[split], array[j]);
				}
				j++;
			}
			swap(array[split], pivot);
			st.push(array[split]);
			array[split] = INF;
		}
		array[i] = st.top();
		st.pop();
	}
}

int main()
{
	quickSort(array, size);
	copy(array, array + size, ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
