#include <bits/stdc++.h>
#include <atcoder/all>
#include <string>

#define rep(i,n) for(int i=0;i < (n);i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define ff first
#define ss second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;

const ll MOD=1000000007ll;
const int MAX=5100000;

using namespace std;
using namespace atcoder;
using mint = modint1000000007;

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

ll i,j,k;

int main()
{
	cin.tie(0);	ios::sync_with_stdio(false);
	ll N; cin >> N;
	vector<ll> X(N), Y(N);
	rep(i, N){cin >> X.at(i) >> Y.at(i);}
	sort(ALL(X));
	sort(ALL(Y));

	// xとyで個別に計算
	// x座標の候補：X[0]～X[N-1]のN通り
	ll ansx, ansy, tmpx, tmpy;
	tmpx = 0; tmpy = 0;
	// a=X[0]としたときの不便さを計算
	rep(i, N){tmpx += X[i] - X[0]; tmpy += Y[i] - Y[0];}
	ansx = tmpx; ansy = tmpy;
	// i=1からN-1まで、差分更新しながら計算
	for(i=1; i<N; i++){
		// i以下の座標：不便さがX[i]-X[i-1]増える
		// i+1以上の座標：不便さがX[i]-X[i-1]減る
		tmpx -= (N - i) * (X[i] - X[i-1]);
		tmpx += i * (X[i] - X[i-1]);
		chmin(ansx, tmpx);
		tmpy -= (N - i) * (Y[i] - Y[i-1]);
		tmpy += i * (Y[i] - Y[i-1]);
		chmin(ansy, tmpy);
	}

	cout << ansx + ansy << endl;

  return 0;
}
