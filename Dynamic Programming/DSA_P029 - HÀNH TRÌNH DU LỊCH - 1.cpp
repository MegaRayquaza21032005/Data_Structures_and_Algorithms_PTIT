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

int a[1009][1009], n, res = INT_MAX;
int visited[1009];
void input(int n)
{
    FOR(i, 1, n)
    {
        FOR(j, 1, n) cin >> a[i][j];
    }
}
void Try(int i, int sum, int cnt)
{
    if(sum > res) return;
    if(cnt == n)
    {
        res = min(res, sum);
        return;
    }
    else
    {
        FOR(j, 1, n)
        {
            if(visited[j] == 0)
            {
                visited[j] = 1;
                Try(j, sum + a[i][j], cnt + 1);
                visited[j] = 0;
            }
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
        res = INT_MAX;
        cin >> n;
        input(n);
        FOR(i, 1, n)
        {
            visited[i] = 1;
            Try(i, 0, 1);
            visited[i] = 0;
        }
        cout << res << endl;

    }
    return 0;
}
