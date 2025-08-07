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

int calc(int x, int y, char c)
{
    if(c == '+') return x + y;
    else if(c == '-') return x - y;
    else if(c == '*') return x * y;
    else return x / y;
}
int main()
{
    fast;
    int T; cin >> T;
    stack<int> st;
    while(T--)
    {
        string s; cin >> s;
        FOR(i, 0, s.size() - 1)
        {
            if(isdigit(s[i])) st.push(s[i] - '0');
            else
            {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                int res = calc(y, x, s[i]);
                st.push(res);
            }
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}