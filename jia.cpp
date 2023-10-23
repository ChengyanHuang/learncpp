#include <iostream>
using namespace std;
#define MAX 100005
int a[MAX], b[MAX], c[MAX];

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
int main()
{
    string A, B;
    cin >> A >> B;
    cout << jia(A, B) << endl;
    return 0;
}