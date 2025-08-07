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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n;
        vector<int> a (n + 9);
        map<int, int> dem;
        int check = 0;
        FOR(i, 1, n)
        {
            cin >> a[i];
            dem[a[i]]++;
        }
        FOR(i, 1, n)
        {
            if(dem[a[i]] > 1)
            {
                cout << a[i] << endl;
                check = 1;
                break;
            }
        }
        if(check == 0) cout << "NO\n";
    }
}
 