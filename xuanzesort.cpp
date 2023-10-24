#include <iostream>
using namespace std;

int main()
{
    int n, a[1005] = {0}, num = 0, num_z = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            num_z++;
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
                num++;
            }
        }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n'
         << num_z << '\n'
         << num << '\n';
    return 0;
}