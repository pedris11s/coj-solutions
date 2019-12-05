#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if(a + b + c != 180)
        cout << "Error\n";
    else if(a == b && b == c)
        cout << "Equilateral\n";
    else if((a == b && a != c) || (a == c && a != b) || (b == c && a != b))
        cout << "Isosceles\n";
    else if(a != b && b != c && a != c)
        cout << "Scalene\n";
    else
        cout << "Error\n";



	return 0;
}
