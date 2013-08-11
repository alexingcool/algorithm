#include <iostream>

using namespace std;

int getFibonacci(int num)
{
    if (num < 0)
		return -1;
	if (num == 0)
		return 0;

	int fin = 0;
	int first = 0;
	int second = 1;
	int count = 1;
	
	while (count <= num)
	{
		fin = first + second;
		first = second;
		second = fin;
		count++;
	}

	return fin;
}

void main()
{
	for (int i = 0; i <= 10; i++)
	{
		int result = getFibonacci(i);
		cout << "result = " << result << endl;
	}
}
