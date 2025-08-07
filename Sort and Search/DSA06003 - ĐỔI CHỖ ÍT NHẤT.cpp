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

int a[1000009], n, k, cnt = 0;
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        cnt = 0;
        int n; cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        FOR(i, 1, n)
        {
            int idx = i;
            FOR(j, i + 1, n)
            {
                if(a[j] < a[idx])
                {
                    idx = j;
                }
            }
            if(idx != i)
            {
                swap(a[i], a[idx]);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}