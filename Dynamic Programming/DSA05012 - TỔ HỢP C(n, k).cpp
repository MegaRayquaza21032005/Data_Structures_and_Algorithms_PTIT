#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

ll C[1009][1009];
void tohop()
{
	FOR(i, 0, 1000)
	{
		FOR(j, 0, i)
		{
			if(j == 0 || j == i) C[i][j] = 1;
			else
			{
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
				C[i][j] %= mod;
			}
		}
	}
}
int main()
{
    fast;
    tohop();
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        cout << C[n][k] << endl;
    }
    return 0;
}
