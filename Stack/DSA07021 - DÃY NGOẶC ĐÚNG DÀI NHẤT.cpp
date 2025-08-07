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

/*
1
((((((((()((((((())
*/
int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
        stack<int> st;
        string s; cin >> s;
        int res = 0;
        st.push(-1);
        FOR(i, 0, s.size() - 1)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) st.push(i);
                else
                {
                    res = max(res, i - st.top());
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}