#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int temp = 0;
    int i, j, k;
    for (i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (j = 1; j < 10; j++)
    {
        for (k = 1; k < 10; k++)
        {
            if (a[k - 1] > a[k])
            {
                temp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}