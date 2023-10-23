#include <iostream>
#include <string>
using namespace std;

void chu(string A, int b)
{
    string ans = "";
    int a = 0, w;
    for (int i = 0; i < A.size(); i++)
    {
        a = a * 10 + (A[i] - '0');
        w = a / b;
        ans += (char)(w + '0');
        a = a % b;
    }
    while (ans.size() > 1 && ans[0] == '0')
        ans.erase(0, 1);
    cout << ans << ' ' << a << endl;
}

int main()
{
    string A;
    int x;
    cin >> A >> x;
    chu(A, x);
    return 0;
}