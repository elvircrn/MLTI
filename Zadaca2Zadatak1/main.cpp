#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int n = 4;
vector <int> taut = { 3, 7, 10, 11, 12, 13, 14 };
vector <char> literal = { 'M', 'W', 'G', 'Y' };
bool values [123123];

string binStr(int number, int width)
{
	stringstream ss;
	int power = (1<<width);
	for (int i = power; i >= 1; i /= 2)
		ss << ((i & number) == i);
	return ss.str();
}

string getLiteral(int number, int width)
{
	if (number == 0)
		return "T";
	int index = width - 1;
	string ret = "";
	int power = (1<<(width - 1));
	for (int i = power; i >= 1; i /= 2, index--)
		if ((i & number) == i)
			ret = literal [index] + ret;
	return ret;
}

int main()
{
	int matrix [1<<n] [10];
	memset (matrix, 0, sizeof matrix);
	for (int x : taut)
	{
		matrix [x] [0] = true;
		values [x] = true;
	}

	int column = 1;

    for (int j = 1; j < (1<<n); j *= 2)
	{
        for(int i = 0; i < (1<<n); i++)
		{
            if ((i & j) == j)
                values [i] ^= values [i-j];
			matrix [i] [column] = values [i];
		}

		column++;
    }

	for (int i = 0; i < (1<<n); i++, cout << endl)
	{
		cout << setw(3) << i << " " << binStr(i, n - 1) << "   ";
		for (int power = 1, j = 0; j <= column; j++, power *= 2)
			if (j != column)
                cout << setw(5) << matrix [i] [j];
            else if (values [i])
                cout << " " << getLiteral(i, n);
	}

	return 0;
}
