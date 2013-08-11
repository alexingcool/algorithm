#include <iostream>
#include <cassert>

using namespace std;

double unsignedExponent(double base, int exp)
{
  assert(exp >= 0);

    if (exp == 0)
		return 1;

	double result = unsignedExponent(base, exp >> 1);
	result *= result;
	if (exp & 0x01)
		result *= base;

	return result;
}

double unsignedExponent2(double base, int exp)
{
	assert(exp >= 0);

	if (exp == 0)
		return 1;

	double result = 1.0;
	while (exp != 0)
	{
		if (exp & 0x01)
			result *= base;
		base *= base;
		exp >>= 1;
	}

	return result;
}

double unsignedExponent3(double base, int exp)
{
	assert(exp >= 0);

	if (exp == 0)
		return 1.0;

	if (exp & 0x01)
		return base * unsignedExponent3(base, exp - 1);
	double result = unsignedExponent3(base, exp >> 1);

	return result *= result;
}

void main()
{
	cout << "test for unsignedExponent" << endl;
	for (int i = 0; i <= 10; i++)
	{
		double result = unsignedExponent(2, i);
		cout << "result = " << result << endl;
	}
	cout << "test for unsignedExponent2" << endl;
	for (int i = 0; i <= 10; i++)
	{
		double result = unsignedExponent2(2, i);
		cout << "result = " << result << endl;
	}
	cout << "test for unsignedExponent3" << endl;
	for (int i = 0; i <= 10; i++)
	{
		double result = unsignedExponent3(2, i);
		cout << "result = " << result << endl;
	}
}
