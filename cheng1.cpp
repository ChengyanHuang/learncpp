#include <iostream>
#include <string>
using namespace std;
#define m 10000

string jia(string A, string B)
{
    int a[m] = {0}, b[m] = {0}, c[m] = {0};
    int l1 = 0, l2 = 0, i;
    for (i = A.size() - 1; i >= 0; i--)
        a[l1++] = A[i] - '0';
    for (i = B.size() - 1; i >= 0; i--)
        b[l2++] = B[i] - '0';
    int l = max(l1, l2);
    for (i = 0; i < l; i++)
    {
        c[i] = c[i] + a[i] + b[i];
        if (c[i] > 10)
        {
            c[i + 1] += 1;
            c[i] -= 10;
        }
    }
    string ans = "";
    for (i = l - 1; i >= 0; i--)
        ans = ans + char(c[i] + '0');
    return ans;
}

string cheng1(string C, int D)
{
    int a[m] = {0}, c[m] = {0};
    int l1 = 0, i;
    for (i = C.size() - 1; i >= 0; i--)
    {
        a[l1++] = C[i] - '0';
    }
    for (i = 0; i < l1; i++)
    {
        c[i] = c[i] + a[i] * D;
        if (c[i] > 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    if (c[l1] > 0)
    {
        l1++;
    }
    string ans = "";
    for (i = l1 - 1; i >= 0; i--)
        ans = ans + char(c[i] + '0');
    return ans;
}

string cheng(string A, string B)
{
    int i, j, cnt = 0;
    string f, ans = "0";
    for (i = B.size() - 1; i >= 0; i--, cnt++)
    {
        f = cheng1(A, int(B[i] - '0'));
        for (j = 0; j < cnt; j++)
        {
            f = f + '0';
        }
        ans = jia(ans, f);
    }
    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << cheng(x, y) << endl;
}
