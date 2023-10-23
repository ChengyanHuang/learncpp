#include <iostream>
#include <string>
#define MAX 100
using namespace std;

void bigadd(const string a, const string b, string &c)
{
    int alen = a.size();
    int blen = b.size();
    int aarray[MAX] = {0};
    int barray[MAX] = {0};
    int carray[MAX] = {0};

    for (int i = 0; i < alen; i++)
    {
        aarray[i] = a[alen - i - 1] - '0';
    }
    for (int i = 0; i < blen; i++)
    {
        barray[i] = b[blen - i - 1] - '0';
    }
    int m = max(alen, blen);
    for (int i = 0; i < m; i++)
    {
        carray[i] += aarray[i] + barray[i];
        if (carray[i] >= 10)
        {
            carray[i] -= 10;
            carray[i + 1] += 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        c = char(carray[i] + '0') + c;
    }
    if (carray[m] != 0)
    {
        c = char(carray[m] + '0') + c;
    }
    return;
}

void bigsub(const string a, const string b, string &c)
{
    int alen = a.size();
    int blen = b.size();
    int aarray[MAX] = {0};
    int barray[MAX] = {0};
    int carray[MAX] = {0};
    int i;
    for (i = 0; i < alen; i++)
    {
        aarray[i] = a[alen - i - 1] - '0';
    }
    for (i = 0; i < blen; i++)
    {
        barray[i] = b[blen - i - 1] - '0';
    }
    int m = max(alen, blen);
    for (i = 0; i < m; i++)
    {
        carray[i] += (aarray[i] - barray[i]);
        if (carray[i] < 0)
        {
            carray[i] += 10;
            carray[i + 1] -= 1;
        }
    }
    for (i = 0; i < m - 1; i++)
    {
        c = char(carray[i] + '0') + c;
    }
    if (carray[m] != 0)
    {
        c = char(carray[m - 1] + '0') + c;
        i += 1;
    }
    if (carray[i] >= 0)
    {
        c = char(carray[i] + '0') + c;
    }
    else
    {
        c = char(abs(carray[i]) + '0') + c;
        c = '-' + c;
    }
    return;
}

int main()
{
    string a, b, c;
    while (1)
    {
        cin >> a >> b;
        // bigadd(a, b, c);
        bigsub(a, b, c);
        cout << c << '\n';
        c.clear();
    }
    return 0;
}