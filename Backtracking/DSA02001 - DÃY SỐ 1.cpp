#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 9);
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        while(n >= 1)
        {
            cout << "[";
            for(int i = 1; i <= n; ++i)
            {
                cout << a[i];
                if(i != n) cout << " ";
                else cout << "]\n";
                a[i] += a[i + 1];
            }
            n--;
        }
    }
}
 