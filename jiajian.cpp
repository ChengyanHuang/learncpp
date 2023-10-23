#include <iostream>
#include <string>
using namespace std;
#define m 10000
int a[m], b[m], c[m];
int bj(string A, string B)
{
    if (A.size() > B.size())
    {
        return 1;
    }
    if (A.size() < B.size())
    {
        return -1;
    }
    return A.compare(B);
}
string jia(string A, string B)
{
    int l1 = 0, l2 = 0, i;
    for (i = A.size() - 1; i >= 0; i--)
        a[l1++] = A[i] - '0';
    for (i = B.size() - 1; i >= 0; i--)
        b[l2++] = B[i] - '0';
    int l = max(l1, l2);
    for (i = 0; i < l; i++)
    {
        c[i] = c[i] + a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if (c[l] > 0)
        l++;
    string ans = "";
    for (i = l - 1; i >= 0; i--)
        ans = ans + (char)(c[i] + '0');
    return ans;
}
string jian(string A, string B)
{
    int i, j1, j2;
    for (i = A.size() - 1, j1 = 0; i >= 0; i--, j1++)
        a[j1] = A[i] - '0';
    for (i = B.size() - 1, j2 = 0; i >= 0; i--, j2++)
        b[j2] = B[i] - '0';
    for (i = 0; i < j1; i++)
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            c[i] += 10;
            c[i + 1] -= 1;
        }
    }
    while (j1 > 0 && c[j1 - 1] == 0)
    {
        j1--;
    }
    string ans = "";
    for (i = j1 - 1; i >= 0; i--)
    {
        ans = ans + char(c[i] + '0');
    }
    return ans;
}
int main()
{
    string x, y, z;
    cin >> x >> z >> y;
    if (z == "+")
    {
        cout << jia(x, y) << endl;
    }
    else
    {
        int j = bj(x, y);
        if (j == 1)
        {
            cout << jian(x, y) << endl;
        }
        else if (j == -1)
        {
            cout << '-' << jian(y, x) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}