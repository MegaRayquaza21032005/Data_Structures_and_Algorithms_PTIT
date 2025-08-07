#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int cnt[10000009];
bool cmp(int a, int b)
{
    if(cnt[a] != cnt[b]) return cnt[a] > cnt[b];
    else return a < b;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end(), cmp);
        for(int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        memset(cnt, 0, sizeof(cnt));
    }
}
 