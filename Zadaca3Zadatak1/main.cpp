#include <iostream>
#include <functional>
#include <vector>

using namespace std;

function<int(int)> first (function<int(int)> g)
{
    return [&g] (int r) -> int { return g (g (r)); };
}

int main()
{
    return 0;
}
