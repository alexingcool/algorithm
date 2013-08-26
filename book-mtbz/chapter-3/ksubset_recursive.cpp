#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const char *input = "12345";
const int length = strlen(input);

void printCombine(const char *input, const int size, int index, int count, vector<char> &cvec)
{
	if (input == NULL || size <= 0)
		return;

	if (index == size && count != 0)
		return;
	else if (index == size && count == 0)
	{
		copy(cvec.begin(), cvec.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
		return;
	}

	if (count == 0)
	{
		copy(cvec.begin(), cvec.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
		return;
	}

	for (int i = index; i < size; i++)
	{
		cvec.push_back(input[i]);
		printCombine(input, size, i + 1, count - 1, cvec);
		cvec.pop_back();
	}
}

int main()
{
	vector<char> cvec;
	printCombine(input, length, 0, 3, cvec);
	return 0;
}


