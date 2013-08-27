#include <iostream>

using namespace std;

const int kColSize = 4;
const int kRowSize = 4;

int array[kRowSize][kColSize] = {
	1, 2, 8, 9,
	2, 4, 9, 12,
	4, 7, 10, 13,
	6, 8, 11, 15
};

bool is_exist(int array[][kColSize], int row_size, int dist_number) {
	for (int i = 0; i < row_size; i++) {
		if (array[i] == NULL) {
			return false;
		}
	}
	int pos_x = 0;
	int pos_y = kColSize - 1;
	bool ret = false;
	while (pos_x < row_size && pos_y >= 0) {
		if (array[pos_x][pos_y] == dist_number) {
			ret = true;
			break;
		} else if (array[pos_x][pos_y] < dist_number) {
			pos_x++;
		} else {
			pos_y--;
		}
	}

	return ret;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		bool ret = is_exist(array, kRowSize, i);
		if (ret == true) {
			cout << "find " << i << " !!!" << endl;
		} else {
			cout << "find not " << i << " !!!" << endl;
		}
	}

	return 0;
}
