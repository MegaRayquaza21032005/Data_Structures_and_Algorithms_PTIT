#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int x[1009], n, k, cnt = 0;
int mark[1009];
vector<string> v;
void Try(int i)
{
    for(int j = x[i - 1] + 1; j <= n - k + i; ++j)
    {
        x[i] = j;
        if(i == k)
        {
            for(int l = 1; l <= k; ++l)
            {
                cout << v[x[l] - 1] << " ";
            }
            cout << endl;
        }
        else Try(i + 1);
    }
}
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        set<string> se;
        for(int i = 1; i <= n; ++i)
        {
            string s;
            cin >> s;
            se.insert(s);
        }
        for(auto x : se) v.push_back(x);
        n = v.size();
        Try(1);
    }
}
 