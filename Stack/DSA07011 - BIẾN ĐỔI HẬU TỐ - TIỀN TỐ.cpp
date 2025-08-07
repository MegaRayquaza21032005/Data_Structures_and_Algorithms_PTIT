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
    stack<string> st;
    while(T--)
    {
        string s; cin >> s;
        FOR(i, 0, s.size() - 1)
        {
            string res = "";
            if(isalpha(s[i])) st.push(res + s[i]);
            else
            {
                string x = st.top(); st.pop();
                string y = st.top(); st.pop();
                res += s[i] + y + x;
                st.push(res);
            }
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}