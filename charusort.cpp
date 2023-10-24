#include <iostream>
using namespace std;

int main()
{
    int n, a[1005] = {0}, num = 0, t;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        t = a[i];
        int j = i - 1;
        while (j >= 0 && t < a[j])
        {
            a[j + 1] = a[j];
            j--;
            num++;
        }
        a[j + 1] = t;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n'
         << num << '\n';
    return 0;
}