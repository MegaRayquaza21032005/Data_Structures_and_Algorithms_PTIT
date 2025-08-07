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

int a[1009], n, k, res = INT_MAX;
string s[1009], x[1009];
int mark[1009];

int check(string a, string b){
    int cnt = 0;
    for(int i = 0; i<a.size(); i++){
        if(b.find(a[i]) != string::npos){
            cnt++;
        }
    }
    return cnt;
}

void Try(int i, int cnt)
{
    if(i > n)
    {
        res = min(res, cnt);
        return;
    }
    if(cnt > res) return;
    FOR(j, 1, n)
    {
        if(mark[j] == 0)
        {
            x[i] = s[j];
            mark[j] = 1;
            Try(i + 1, cnt + check(x[i], x[i - 1]));
            mark[j] = 0;
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
        res = INT_MAX;
        cin >> n;
        FOR(i, 1, n) cin >> s[i];
        Try(1, 0);
        cout << res << endl;
    }
}