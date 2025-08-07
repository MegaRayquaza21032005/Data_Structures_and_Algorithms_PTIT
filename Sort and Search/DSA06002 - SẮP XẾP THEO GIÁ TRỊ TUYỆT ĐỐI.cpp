#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int n, x;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(abs(x - a.first) != abs(x - b.first)) return abs(x - a.first) < abs(x - b.first);
    else return a.second < b.second;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        vector<int> v(n + 9);
        vector<pair<int, int>> p;
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
            p.push_back({v[i], i});
        }
        sort(p.begin(), p.begin() + n, cmp);
        for(int i = 0; i < n; ++i) cout << p[i].first << ' ';
        cout << endl;
    }
    return 0;
}
 