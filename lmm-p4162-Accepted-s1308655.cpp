#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

//typedef complex<double> point;
//typedef vector<point> polygon;

//struct circle { point p; double r; };
//struct line { point p, q; };
//using segment = line;

struct point{
    ll x, y, z;
    point(ll x, ll y, ll z) : x(x), y(y), z(z){ }
};

point get_vect(point a, point b){
    point ans(b.x - a.x, b.y - a.y, b.z - a.z);
    return ans;
}

point cross(point a, point b){
    point ans(0, 0, 0);
    ans.x = a.y * b.z - a.z * b.y;
    ans.y = -(a.x * b.z - a.z * b.x);
    ans.z = a.x * b.y - a.y * b.x;
    return ans;
}

ll dot(point a, point b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ll vol(point a, point b, point c){

//    cout << a.x << " " << a.y << " " << a.z << endl;
//    cout << b.x << " " << b.y << " " << b.z << endl;
//    cout << c.x << " " << c.y << " " << c.z << endl;

    point d = cross(a, b);
//    cout << d.x << " " << d.y << " " << d.z << endl;

    return dot(d, c);
}

bool ok(vector<point> &p){

    ll plane = vol(get_vect(p[0], p[1]), get_vect(p[0], p[2]), get_vect(p[0], p[3]));
    return plane == 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    point a = cross(point(1, 0, 0), point(2, 0, 0));
//
//    cout << a.x << " " << a.y << " " << a.z << endl;
//    return 0;

    int n;
    cin >> n;

    vector<point> p(n, point(0, 0, 0));
    for(int i = 0; i < n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        p[i] = point(x, y, z);
    }

    if(n <= 3){
        cout << "TAK" << endl;
        return 0;
    }

    point p0 = p[0];
    point p1 = p[1];
    point p2 = point(0, 0, 0);
    bool ok = false;


    for(int i = 2; i < n; i++){
        point c = cross(get_vect(p0, p1), get_vect(p0, p[i]));
        if(c.x == 0 && c.y == 0 && c.z == 0)
            continue;
        p2 = p[i];
        ok = true;
        break;
    }

    if(!ok){
        cout << "TAK" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){

        ll v = vol(get_vect(p0, p1), get_vect(p0, p2), get_vect(p0, p[i]));
        if(v != 0){
            cout << "NIE" << endl;
            return 0;
        }
    }

    cout << "TAK" << endl;

//    if(n == 4){
//        for(int i = 0; i + 3 < n; i++){
//            ll plane = vol(get_vect(p[i], p[i + 1]), get_vect(p[i], p[i + 2]), get_vect(p[i], p[i + 3]));
//    //        cout << plane << endl;
//            if(plane != 0){
//                cout << "NIE" << endl;
//                return 0;
//            }
//        }
//        cout << "TAK" << endl;
//        return 0;
//    }
//
//    for(int i = 0; i + 4 < n; i++){
//
//        int lo = i, hi = i + 4;
//
//        vector<point> v;
//
//        for(int j = lo; j <= hi; j++){
//            v.clear();
//            for(int k = lo; k <= hi; k++){
//                if(k != j)
//                    v.push_back(p[k]);
//            }
//            if(!ok(v)){
//                cout << "NIE" << endl;
//                return 0;
//            }
//        }
//    }



    return 0;
}
