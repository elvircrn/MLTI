#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define LAZY 20

using Edge = pair <int, int>;
using Graph = vector <Edge>;

template <class T>
	using Matrix = std::vector <std::vector <T> >;

template <class T>
Matrix<T> createMatrix (int m, int n)
{
	return Matrix<T> (m, vector <T> (n));
}

template <class T>
void printMatrix (Matrix <T> mat)
{
	int n = mat.size(), m = mat [0].size();
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)
			cout << mat [i] [j] << ' ';
	return;
}

vector <Edge> getEdges(Matrix<bool> m)
{
    vector <Edge> v;
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m.size(); j++)
            if (m [i] [j])
                v.emplace_back(i, j);
    return v;
}

void printGraph(Graph g)
{
    cout << "{";
	for (auto e : g)
		cout << " (" << e.first + 1 << ", " << e.second + 1 << ")";
    cout << " }" << endl;
}

void printGraph(Matrix<bool> m)
{
    printGraph(getEdges(m));
}

Matrix<bool> composition (Matrix <bool> a, Matrix<bool> b)
{
	auto ret = createMatrix<bool>(a.size(), a.size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
		{
			bool what = false;

			for (int k = 0; k < a.size(); k++)
				what |= (a [i] [k] & b [k] [j]);

			ret [i] [j] = what;
		}
	return ret;
}

void relate(Matrix<bool> &mat, vector <int> r)
{
	for (int &x : r)
		x--;
	for (int i = 0; i < r.size(); i++)
	{
		for (int j = 0; j < r.size(); j++)
		{
			mat [r [i]] [r [j]] = true;
			mat [r [j]] [r [i]] = true;
		}
	}
}

void relate(Matrix<bool> &mat, Graph g)
{
	for (Edge e : g)
		mat [e.first - 1] [e.second - 1] = true;
}

vector <pair <int, int> > getEdge (const vector <vector <bool> > &mat)
{
	vector <pair <int, int> > edges;
	int n = mat.size();
	int m = mat [0].size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (mat [i] [j])
				edges.emplace_back(i + 1, j + 1);
	return edges;
}

Matrix<bool> power (Matrix <bool> a, int p)
{
	vector <vector <bool> > ret = a;
	if (p == -1)
	{
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < i; j++)
			{
				bool x = ret [i] [j];
				bool y = ret [j] [i];
				swap (x, y);

				ret [i] [j] = x;
				ret [j] [i] = y;
			}
	}
	else
	{
		for (int i = 0; i < p; i++)
			ret = composition (ret, a);
	}
	return ret;
}


Matrix<bool> plusMe(Matrix <bool> a)
{
	return power (a, LAZY);
}

Matrix<bool> starMe(Matrix<bool> a)
{
	auto ret = plusMe(a);
	for (int i = 0; i < a [0].size(); i++)
		a [i] [i] = true;
	return a;
}

vector <int> getVertices (Matrix<bool> m)
{
	vector <int> v;
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			if (m [i] [j])
			{
				v.push_back(i + 1);
				break;
			}
		}
	}
	return v;
}

int main()
{
	auto R = createMatrix<bool> (6, 6);
	relate(R, { { 1, 4 }, { 2, 1 }, { 4, 4 }, { 5, 1 }, { 6, 4 } });

	cout << "R" << endl;
	printMatrix(R);
	cout << endl;
	cout << "R = "; printGraph(R);

	cout << endl;

	cout << "R^-1" << endl;
	printMatrix(power(R, -1));
	cout << endl;
	cout << "R^-1 = "; printGraph(power(R, -1));

	cout << endl;

	cout << "R^2" << endl;
	printMatrix(power(R, 2));
	cout << endl;
	cout << "R^2 = "; printGraph(power(R, 2));

	cout << endl;

	cout << "R^3" << endl;
	printMatrix(power(R, 3));
	cout << endl;
	cout << "R^3 = "; printGraph(power(R, 3));

	cout << endl;

	cout << "R+" << endl;
	printMatrix(plusMe(R));
	cout << endl;
	cout << "R+ = "; printGraph(plusMe(R));

	cout << endl;

	cout << "R*" << endl;
	printMatrix(starMe(R));
	cout << endl;
	cout << "R* = "; printGraph(starMe(R));

	cout << endl;

	cout << "R o R^-1" << endl;
	printMatrix(composition(R, power(R, -1)));
	cout << endl;
	cout << "R o R^-1 = "; printGraph(composition(R, power(R, -1)));

	cout << endl;

	cout << "R^2 o R^-1" << endl;
	printMatrix(composition(power(R, 2), power(R, -1)));
	cout << endl;
	cout << "R^2 o R^-1 = "; printGraph(composition(power(R, 2), power(R, -1)));



    return 0;
}
































