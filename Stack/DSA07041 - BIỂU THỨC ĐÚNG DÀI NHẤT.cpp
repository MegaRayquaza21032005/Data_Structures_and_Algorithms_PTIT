#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
const int mod = 1e9 + 7;

int main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        string s; cin >> s;
        stack<char> st;
        int res = 0;
        FOR(i, 0, s.size() - 1)
        {
            if(s[i] == '(') st.push(s[i]);
            else
            {
                if(!st.empty())
                {
                    st.pop();
                    res += 2;
                }
            }
        }
        cout << res << endl;   
    }
    return 0;
}

