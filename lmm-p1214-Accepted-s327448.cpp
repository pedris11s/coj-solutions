#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    float a,s;
    for(int i= 0; i < t; i++)
    {
    	scanf("%f%f", &a, &s);
    	float sol = sqrt( (s * s) - (4 * a) ) / 2;
    	printf("%.2f\n", sol);
    }

    return 0;
}