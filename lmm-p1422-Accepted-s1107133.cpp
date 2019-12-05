#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000003
#define endl '\n'
#define MOD 1000000009
#define ll long long

struct Node {
	ll sum;
	ll lazy;
	bool laz;
	Node() {
		this-> lazy = 1;
	}
	Node(ll v, ll lazy, bool laz) :
		sum(v), lazy(lazy), laz(laz) {
	}
}ST[MAXN * 4 +2];

ll N, Q, x, y, v, op;

ll A[MAXN];

void create(ll node, ll a, ll b) {
	if (a == b) {
		ST[node] = Node(1 , 1, 0);
		return;
	}
	create(2 * node, a, (a + b) >> 1);
	create(2 * node + 1, ((a + b) >> 1) + 1, b);

	ST[node].sum = (ST[2 * node].sum + ST[2 * node + 1].sum) % MOD;
	ST[node].lazy = 1;
}

void propagate(ll node, ll a, ll b, ll nv) {
	ST[node].lazy = (ST[node].lazy * nv) % MOD;
	ST[node].sum = (ST[node].sum * nv) % MOD;
	ST[node].laz = 1;
}

void update(ll node, ll a, ll b, ll nv, ll x, ll y) {
	if (a > y || b < x)
		return;
	if (a >= x && b <= y) {
		ST[node].lazy = (ST[node].lazy * nv) % MOD;
		ST[node].sum = (ST[node].sum * nv) % MOD;
		ST[node].laz = true;
		return;
	}

	if (ST[node].laz) {
		propagate(2 * node, a, (a + b) >> 1, ST[node].lazy);
		propagate(2 * node + 1, ((a + b) >> 1) + 1, b, ST[node].lazy);
		ST[node].lazy = 1;
		ST[node].laz = false;
	}

	update(2 * node, a, (a + b) >> 1, nv, x, y);
	update(2 * node + 1, ((a + b) >> 1) + 1, b, nv, x, y);

	ST[node].sum = (ST[2 * node].sum + ST[2 * node + 1].sum) % MOD;
	ST[node].lazy = 1;
	return;
}

ll query(ll node, ll a, ll b, ll x, ll y) {
	if (a > y || b < x)
		return 0;
	if (a >= x && b <= y)
	{
		//cout << a << " " << b << " " << ST[node].sum << endl;
		return ST[node].sum;
	}

	if (ST[node].laz) {
		propagate(2 * node, a, (a + b) >> 1, ST[node].lazy);
		propagate(2 * node + 1, ((a + b) >> 1) + 1, b, ST[node].lazy);
		ST[node].lazy = 1;
		ST[node].laz = false;
	}
	//cout << a << " " << b << " " << ST[node].sum << "asd"<< endl;
	return (query(2 * node, a, (a + b) >> 1, x, y)
			+ query(2 * node + 1, ((a + b) >> 1) + 1, b, x, y)) % MOD;
}

int main() {

	cin.sync_with_stdio();cin.tie(0);

	while(cin >> N >> Q)
	{

		memset(ST,0,sizeof(ST));
		create(1, 1, N);

		while (Q--) {
			cin >> op;
			if (op == 0) {
				//update
				cin >> x >> y >> v;
				if(x > y) swap(x,y);
				update(1, 1, N, v, x, y);
			} else {
				cin >> x >> y;
				if(x > y) swap(x,y);
				cout << query(1, 1, N, x, y) << endl;
			}
		}
	}
	return 0;
}

