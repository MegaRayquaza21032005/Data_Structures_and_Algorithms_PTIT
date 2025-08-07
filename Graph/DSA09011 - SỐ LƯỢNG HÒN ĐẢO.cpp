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

int a[1009][1009], n, m, cnt = 0;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(int n, int m)
{
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin >> a[i][j];
        }
    }
}

void loang(int i, int j)
{
    a[i][j] = 0;
    FOR(k, 0, 8 - 1)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1)
        {
            loang(i1, j1);
        }
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        input(n, m);
        cnt = 0;
        FOR(i, 1, n)
        {
            FOR(j, 1, m)
            {
                if(a[i][j] == 1)
                {
                    cnt++;
                    loang(i, j);
                }
            }
        }
        cout << cnt << endl;
    } 
    return 0;
}