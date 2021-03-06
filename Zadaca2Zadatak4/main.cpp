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

namespace MLTI
{
	string binStr(int number, int width)
	{
		stringstream ss;
		int power = (1<<width);
		for (int i = power; i >= 1; i /= 2)
			ss << ((i & number) == i);
		return ss.str();
	}

	string getLiteral(vector <char> literals, int number, int width, bool full = false)
	{
		if (!full)
		{
			if (number == 0)
				return "T";
			int index = width - 1;
			string ret = "";
			int power = (1<<(width - 1));
			for (int i = power; i >= 1; i /= 2, index--)
				if ((i & number) == i)
					ret = literals [index] + ret;
			return ret;
		}
		else
		{
			int index = width - 1;
			string ret = "";
			int power = (1<<(width - 1));
			for (int i = power; i >= 1; i /= 2, index--)
			{

				if ((i & number) == i)
					ret = (char)literals [index] + ret;
				else
					ret = (char)tolower (literals [index]) + ret;
				/*
				if ((i & number) == i)
					ret = literals [index] + ret;
				else
				{
					ret = literals [index] + ret;
					ret = '!' + ret;
				}*/
			}
			return ret;
		}
	}

	bool getBit(int number, int index)
	{
		return (number & (1<<index)) == (1<<index);
	}

	bool toBinary(char c)
	{
		return c == '1';
	}

	int bitCount(int number, int width)
	{
		int ret = 0;
		for (int i = 0; i < width; i++)
			ret += getBit(number, i);
		return ret;
	}

	int notCount(int number, int width)
	{
		int ret = 0;
		for (int i = 0; i < width; i++)
			ret += !getBit(number, i);
		return ret;
	}

	bool isPow(int n)
	{
		return (n & (n - 1) == 0);
	}

	bool canBind(int n, int m)
	{
		return isPow(fabs(n - m));
	}
}

using namespace MLTI;

int main()
{
	vector <char> literals = { 'G', 'W', 'C', 'U' };
	vector <int> minterms;
	int n = literals.size();
	vector <string> DNFs = { "0010", "1110", "100x", "010x", "10x1", "01x1" };
	//01001
	vector <bool> taut (1 << n + 5, 0);

	int power = (1<<n);

	bool valid;
	for (int i = 0; i < power; i++)
	{
		for (string dnf : DNFs)
		{
			valid = true;
			for (int j = 0; j < dnf.length(); j++)
			{
				if (dnf [j] != 'x' && toBinary(dnf [j]) != getBit(i, j))
				{
					valid = false;
					break;
				}
			}

			if (valid)
				break;
		}
		taut [i] = valid;
		if (taut [i])
			minterms.push_back(i);
	}

	sort (minterms.begin(), minterms.end(), [&n] (int a, int b) -> bool { return notCount(a, n) < notCount(b, n); });

	cout << "bitCount min: " << endl;
	for (int x : minterms)
		cout << notCount(x, n) << "  " << getLiteral(literals, x, n, true) << " " << x << endl;
	int count = 0;

	cout << "lex minterms: " << endl;
	for (int i = 0; i < power; i++)
		if (taut [i])
			cout << i << endl;

	for (int i = 0; i < power; i++)
	{
		count += taut [i];
		if (taut [i])
			cout << getLiteral(literals, i, n, true) << endl;
	}

/*
	vector <int> help minterms;
	bool changed = true;
	while (changed)
	{
		bool visited [100];
		changed = false;
		
		memset (visited, false, sizeof visited);

		for (int i = 0; i < minterms.size() - 1; i++)
		{
			for (int j = i + 1; j < minterms.size(); j++)
			{
				if (!visited [i] && !visited [j] && canBind (minterms [i], minterms [j]))
				{
					visited [i] = true;
					visited [j] = true;
				}

			}
		}
	}
*/

	return 0;
}




/*
(G and not W and C and not U) or 
(not G and W and C and not U) or 
(W and G and not C) or 
(W and G and U) or 
(not W and not G and not C) or 
(not W and not G and U)


!M!P!Z!Y!J
M!P!Z!Y!J
!MP!Z!Y!J
MP!Z!Y!J
!M!PZ!Y!J
M!PZ!Y!J
!MPZ!Y!J
MPZ!Y!J
M!PZY!J
MPZY!J
M!PZ!YJ
M!PZYJ
MPZYJ
*/
