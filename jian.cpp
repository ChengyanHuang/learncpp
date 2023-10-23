#include <iostream>
using namespace std;
#define MAX 100005
int a[MAX], b[MAX], c[MAX];

int bj(string A, string B)
{
    if (A.size() > B.size())
        return 1;
    if (A.size() < B.size())
        return -1;
    return A.compare(B);
    // int l = A.size();
    // for (int i = 0; i <= l - 1; i++)
    // {
    //     if (A[i] > B[i])
    //         return 1;
    //     if (A[i] < B[i])
    //         return -1;
    // }
    // return 0;
}

string jian(string A, string B)
{
    int l1 = 0, l2 = 0, i;
    for (i = A.size() - 1; i >= 0; i--)
        a[l1++] = A[i] - '0';
    for (i = B.size() - 1; i >= 0; i--)
        b[l2++] = B[i] - '0';

    for (i = 0; i < l1; i++)
    {
        c[i] = a[i] - b[i];
        if (c[i] < 0)
        {
            c[i] += 10;
            a[i + 1] -= 1;
        }
    }
    while (l1 > 0 && c[l1 - 1] == 0)
        l1--;

    string ans = "";
    for (i = l1 - 1; i >= 0; i--)
        ans = ans + (char)(c[i] + '0');
    return ans;
}
int main()
{
    string A, B;
    cin >> A >> B;
    int dx = bj(A, B);
    if (dx == 1)
    {
        cout << jian(A, B) << endl;
    }
    else if (dx == -1)
    {
        cout << "-" << jian(B, A) << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}