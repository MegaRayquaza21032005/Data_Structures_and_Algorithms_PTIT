#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define pi pair<int, int>
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

int v, e;
ll dp[1009][1009];

void input(int v, int e)
{
	FOR(i, 1, e)
	{
		int x, y, w; cin >> x >> y >> w;
		dp[x][y] = w;
		dp[y][x] = w;
	}
}

void Floyd()
{
	FOR(i, 1, v)
	{
		FOR(j, 1, v)
		{
			if(dp[i][j] == 0) dp[i][j] = 1e9;
		}
	}
	FOR(i, 1, v) dp[i][i] = 0;
	FOR(k, 1, v)
	{
		FOR(i, 1, v)
		{
			FOR(j, 1, v)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main()
{
    fast;
    int T = 1; 
	//cin >> T;
    while(T--)
    {
    	cin >> v >> e;
		input(v, e);
		Floyd();
		int q; cin >> q;
		while(q--)
		{
			int x, y; cin >> x >> y;
			cout << dp[x][y] << endl;
		}
	}
    return 0;
}



