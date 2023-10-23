#include <iostream>
int main()
{
    int year, month, day;
    while (1)
    {
        std::cin >> year >> month >> day;

        int month31 = month / 2;
        int days = month * 30 + day + month31 - 30;

        if (month > 2)
            days -= 2;
        if (month == 9 || month == 11)
            days += 1;

        if (days % 5 == 0 || days % 5 == 4)
            std::cout << "shaiwang\n";
        else
            std::cout << "dayu\n";
    }
}