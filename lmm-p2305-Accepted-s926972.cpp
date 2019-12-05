#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b) for(int i = a; i < b; i++)
#define sz size()
#define pb push_back
#define mp make_pair
#define PI M_PI
using namespace std;
int n;
double ac, ab, bc;


int main()
{
    scanf("%d", &n);
    FOR(i, n)
    {
        scanf("%lf%lf%lf", &ab,&ac,&bc);
        double angACB = acos( (ab*ab - ac*ac - bc*bc)/(-1.0*2*ac*bc));
        double angABC = acos ((ac*ac - ab*ab - bc*bc)/(-1.0*2*ab*bc));
        double angQBP = PI-angABC;
        double angQCA = PI-angACB;
        double angCAB = PI-angACB-angABC;
        double ap = ab*2;
        double angRAP = PI-angCAB;
        double ar = ac;
        double angQCR = PI-angACB;
        double qc = bc;
        double cr = ac*2;
        double areaTotal = 0;
        double bp = ab;
        double bq = bc*2;
        areaTotal += ac*ab*sin(angCAB)/2.0;
        areaTotal += ar*ap*sin(angRAP)/2.0;
        areaTotal += bp*bq*sin(angQBP)/2.0;
        areaTotal += qc*cr*sin(angQCR)/2.0;
        printf("%.1lf\n", areaTotal);


    }
    return 0;
}
