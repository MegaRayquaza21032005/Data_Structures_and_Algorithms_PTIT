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

ll calc(ll x, ll y, string c)
{
    if(c == "+") return x + y;
    else if(c == "-") return x - y;
    else if(c == "*") return x * y;
    else return x / y;
}
int main()
{
    fast;
    int T; cin >> T;
    stack<ll> st;
    while(T--)
    {
        int n; cin >> n;
        string s;
        FOR(i, 0, n - 1)
        {
            cin >> s;
            if(s != "+" && s != "-" && s != "*" && s != "/") st.push(stoi(s));
            else
            {
                ll x = st.top(); st.pop();
                ll y = st.top(); st.pop();
                ll res = calc(y, x, s);
                st.push(res);
            }   
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}