#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i < (n);i++)
#define ff first
#define ss second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;

using namespace std;
using namespace atcoder;

int i,j,k,tmp;
int ans = 0;

int main()
{
	cin.tie(0);	ios::sync_with_stdio(false);
	int H, W, Q; cin >> H >> W >> Q;
	int P[H][W]; rep(i,H){rep(j,W){P[i][j] = 0;}}
	dsu d(H * W);

	rep(i, Q){
		int t; cin >> t;
		if(t == 1){
			int r, c; cin >> r >> c; r--; c--;
			int now = r * W + c;
			P[r][c] = 1;
			if(r > 0){if(P[r-1][c] == 1){d.merge(now, now - W);}}
			if(r < H-1){if(P[r+1][c] == 1){d.merge(now, now + W);}}
			if(c > 0){if(P[r][c-1] == 1){d.merge(now, now - 1);}}
			if(c < W-1){if(P[r][c+1] == 1){d.merge(now, now + 1);}}
		}
		else{
			int ra, ca, rb, cb;
			cin >> ra >> ca >> rb >> cb;
			ra--; ca--; rb--; cb--;
			int posa = ra * W + ca;
			int posb = rb * W + cb;
			if(P[ra][ca] == 1 && P[rb][cb] == 1 && d.same(posa, posb) == true){
				cout << "Yes" << endl;
			}
			else{cout << "No" << endl;}
		}
	}

  return 0;
}