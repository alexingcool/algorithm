/*输入为123，输出1,2,3,12,13,23,123
 * 递归解法
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void PrintPartition(const char *input_string, const int string_length, int index, int count, vector<char> &cvec) {
	if (input_string == NULL || string_length <= 0) {
		return;
	}
	if (count == 0) {
		copy(cvec.begin(), cvec.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
		return;
	}

	if (index == string_length) {
		return;
	}

	for (int i = index; i < string_length; i++) {
		cvec.push_back(input_string[i]);
		PrintPartition(input_string, string_length, i + 1, count - 1, cvec);
		cvec.pop_back();
	}
}

int main()
{
	const char *string_input = "123";
	const int string_length = strlen(string_input);	
	vector<char> cvec;
	for (int i = 1; i <= string_length; i++) {
		PrintPartition(string_input, string_length, 0, i, cvec);
	}

	return 0;
}
