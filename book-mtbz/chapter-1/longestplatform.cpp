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

//recursive solution
int findMaxLen(int *array, int size, int index)
{
	if (array == NULL || size <= 0)
		return -1;

	if (index == size)
	{
		return 1;
	}

	int length = findMaxLen(array, size, index + 1);

	if (array[index - length] == array[index])
		length++;

	return length;
}

//把所有平台和他们的位置找出来
map<int, int> posMap;

int FindLongestPlatform(int *array, int size)
{
	if (array == NULL || size <= 0)
		return -1;

	int prefix = INF;
	for (int i = 0; i < size; i++)
	{
		if (array[i] != prefix)
		{
			prefix = array[i];
			posMap.insert(make_pair(array[i], i));
		}
	}

	return 0;
}

//找出所有平台
struct Node
{
	Node(int left = 0, int right = 0) : start(left), end(right) {}
	int start;
	int end;
};

int findMaxLen(int *array, int size, vector<Node> &nvec)
{
	if (array == NULL || size <= 0)
		return -1;

	int leftIndex = 0;
	int rightIndex = 0;

	while (rightIndex < size)
	{
		if (array[rightIndex] == array[leftIndex])
			rightIndex++;
		else
		{
			nvec.push_back(Node(leftIndex + 1, rightIndex));
			leftIndex = rightIndex;
		}
	}
	nvec.push_back(Node(leftIndex +1, rightIndex));

	return 0;
}

int main()
{
	int longest_length = GetLongestLength2(array, kArraySize);
	cout << "longest_length = " << longest_length << endl;

	return 0;
}

