#include <cstdio>
#include <cstdlib>

int main()
{
	int t;
	scanf("%d",&t);
	float h,c;
	float average = 0;
	for(int i = 0; i < t; i++)
	{
	     scanf("%f%f", &h, &c);
	     float sol = ((h * h) - (c * c)) / (2 * h);
	     average += sol;
	     printf("%.1f\n",sol);
	}
	printf("%.1f\n",average / t);
	return 0;
}
