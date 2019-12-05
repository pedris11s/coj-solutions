#include <bits/stdc++.h>

using namespace std;

#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> Pol;
const double EPS = 1e-10;

enum {OUT, ON, IN};

double cross(P a, P b)
{
    return imag(conj(a) * b);
}

double dot(P a, P b) //2
{
    return (conj(a)*b).X;
}

int contains (const Pol & pol, const P & p)
{
    bool in = false;
    for (int i = 0; i <pol.size (); ++i)
    {
        P a = pol[i] - p, b = pol[(i+1)%pol.size()] - p;
        if (imag (a)> imag (b)) swap (a, b);
        if (imag (a) <= 0 && 0 < imag (b))
            if (cross (a, b) <0) in = !in;
        if (cross (a, b) == 0 && dot (a, b) <= 0) return ON;
    }
    return in? IN: OUT;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("in","r",stdin);

    int t;
    cin >> t;
    while(t--){
        int N, T;
        cin >> N >> T;
        Pol pol;
        for(int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            pol.push_back(P(x, y));
        }

        int sol = 0;
        while(T--){
            int x, y;
            cin >> x >> y;


            if(contains(pol, P(x, y)) == IN){
            //if(pointInPolygon(pol, P(x, y))){
                //cout << "yes\n";
                sol++;
            }
            //else
                //cout << "no\n";

        }
        cout << sol << "\n";
    }

    return 0;
}
