#include <iostream>
using namespace std;

long long
jiecheng(int n)
{
    if (n == 1)
        return 1;
    else
        return n * jiecheng(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << jiecheng(n);
    return 0;
}