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

int main()
{
    fast;
    int T; cin >> T;
    stack<ll> st;
    while(T--)
    {
        int n; cin >> n;
        vector<int> res(n), a(n);
        stack<int> st;
        FOR(i, 0, n - 1) cin >> a[i];
        res[n - 1] = -1;
        st.push(a[n - 1]);
        FORD(i, n - 2, 0)
        {
            if(!st.empty())
            {
                if(a[i] < st.top())
                {
                    res[i] = st.top();
                    st.push(a[i]);
                }
                else
                {
                    while(!st.empty() && a[i] >= st.top())
                    {
                        st.pop();
                    }
                    if(st.empty()) res[i] = -1;
                    else res[i] = st.top();
                    st.push(a[i]);
                }
            }
            else // hơi thừa
            {
                res[i] = -1;
                st.push(a[i]);
            }
        }
        FOR(i, 0, n - 1) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}