#include <iostream>
#include <string>
using namespace std;
#define m 10000
int a[m], b[m], c[m];

string cheng(string A, string B)
{
    int l1 = 0, l2 = 0, i, j;
    for (i = A.size() - 1; i >= 0; i--)
        a[l1++] = A[i] - '0';
    for (i = B.size() - 1; i >= 0; i--)
        b[l2++] = B[i] - '0';

    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < l2; j++)
        {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= 10)
            {
                c[i + j + 1] = c[i + j] / 10;
                c[i + j] = c[i + j] % 10;
            }
        }
    }
    int l = (l1 - 1) + (l2 - 1) + 1;
    if (c[l] > 0)
        l++;
    string ans = "";
    for (i = l - 1; i >= 0; i--)
        ans = ans + (char)(c[i] + '0');
    return ans;
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << cheng(A, B) << endl;
    return 0;
}