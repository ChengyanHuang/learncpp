#include <iostream>
#include <string>
using namespace std;
#define m 10000

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
    int a[m] = {0}, b[m] = {0}, c[m] = {0};
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

/// @brief 乘法的每一轮乘函数
/// @param A  被乘数 ：字符串
/// @param B  乘数，由于是一轮操作，所以是0-9中的一个int
/// @return  一轮的乘积 ：字符串
string danbucheng(string A, int B)
{
    int i, l = A.size();
    int tmp[m] = {0};
    // 类似于加法运算，B*每一个A的数字，乘积存在tmp数组里
    for (i = 0; i < l; i++)
    {
        tmp[i] = tmp[i] + int(A[l - i - 1] - '0') * B;
        tmp[i + 1] = tmp[i] / 10; // 进位
        tmp[i] = tmp[i] % 10;
    }
    if (tmp[l] > 0)
        l++;
    // while (tmp[l] == 0)
    //     l--;
    // cout << l << endl;

    // 以下拼接成字符串，类似于加法函数
    string ans = "";
    for (i = l - 1; i >= 0; i--)
        ans = ans + (char)(tmp[i] + '0');
    // cout << A << " " << B << " " << ans << endl;
    return ans;
}

/// @brief 乘法的总运算，利用乘法每一轮运算
/// @param A  被乘数 ：字符串
/// @param B  乘数 ：字符串
/// @return   总乘积 ：字符串
string cheng(string A, string B)
{
    string ans = "0";

    int i = B.size() - 1, j = 0;
    for (; i >= 0; i--, j++)
    { // 每一个B都去乘A的整体，利用单步乘函数，结果存在dan里
        string dan = danbucheng(A, int(B[i] - '0'));
        for (int k = 0; k < j; k++)
        {
            // 高位乘每一轮结果要补若干个0，因为B不是个位，而是十位、百位去乘A
            dan = dan + "0";
        }
        // 把若干个单步乘积加起来，就像乘法竖式，利用加法函数
        ans = jia(ans, dan);
    }
    return ans;
}

/// @brief 除法的总运算
/// @param A  被除数 ：字符串
/// @param B  除数 ：字符串
/// @return   无返回，直接打印结果和余数
void chu(string A, string B)
{
    // 先看看是不是除0，如果除0直接报错。利用比较函数
    if (bj(B, "0") == 0)
    {
        cout << "Can't divide 0" << endl;
        return;
    }
    // 再看看是不是除数比被除数大，如果大直接得0余除数，利用比较函数
    if (bj(A, B) < 0)
    {
        cout << 0 << " ...... " << A << endl;
        return;
    }

    string ans = "";
    int l1 = A.size(), l2 = B.size(), i;
    int d = l2;
    // 单步处理，先把被除数前l2位截出来，就像除法竖式
    string dan = A.substr(0, d);

    while (1)
    {
        // cout << dan << endl;

        while (bj(dan, B) < 0 && d <= l1)
        {
            d++;
            // 如果被除数前几位没有除数大，就往后多加一位，直到比除数大
            dan = dan + A[d - 1];
            // 如果被除数不够一次，除法竖式上边结果加一个0
            if (ans != "")
                ans = ans + "0";
            // cout << dan << endl;
        }
        // 被除数没得加位了，跳出输出结果。
        if (d > l1)
            break;

        // 被除数前多少位比除数大了，开始试探1-9去反乘除数
        for (i = 1; i <= 10; i++)
        {
            // 利用单步乘函数反乘
            string tryres = danbucheng(B, i);
            // 试探到比被除数大了，跳出
            if (bj(tryres, dan) > 0)
                break;
        }
        // 例如乘6比被除数大，那就上边结果填i-1=5
        ans = ans + char('0' + i - 1);
        // 除法竖式的减法，把除数上*（i-1），然后减掉，利用单步乘函数和减函数
        string subres = danbucheng(B, i - 1);
        dan = jian(dan, subres);
        d++;
        // 被除数没得加位了，跳出输出结果。
        if (d > l1)
            break;
        // 被除数可以加位，那就加一位
        dan = dan + A[d - 1];
    }
    i = 0;
    cout << ans << " ...... " << dan << endl;
}

int main()
{
    string x, y, z;
    cin >> x >> z >> y;
    if (z == "+")
    {
        cout << jia(x, y) << endl;
    }
    else if (z == "-")
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
    else if (z == "*")
    {
        cout << cheng(x, y) << endl;
    }
    else if (z == "/")
    {
        chu(x, y);
    }
    return 0;
}