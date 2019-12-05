//by pter

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string meses[13] = {"", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
string dayWeek_20[7] = {"SUNDAY", "MONDAY", "TUESDAY","WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

int year, day;
string month;

int zeller(int y, int m, int d){
 if (m<3) --y, m+=12;
 return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++)
    {
        cin >> year >> month >> day;

        int mes;

        for(int i = 1; i <= 12; i++)
            if(month == meses[i])
            {
                mes = i;
                break;
            }
        int sol = zeller(year, mes, day);
        cout << dayWeek_20[sol] << "\n";

    }
    return 0;
}
