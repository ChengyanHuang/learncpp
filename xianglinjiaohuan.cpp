#include <iostream>
using namespace std;
// 交换一次花费1，2，3，算总花费，冒泡
int main()
{
    int n, a[1005] = {0}, num = 0, num_z = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                flag = 1;
                swap(a[j], a[j - 1]);
                num++;
            }
        }
        if (flag == 0)
            break;
    }
    cout << num * (1 + num) / 2 << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << ' ';
    // cout << '\n'
    //      << num_z << '\n'
    //      << num << '\n';
    return 0;
}