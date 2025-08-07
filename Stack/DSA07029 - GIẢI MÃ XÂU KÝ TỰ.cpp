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

/*
1 vài test case cần lưu ý:
12[b] --> bbbbbbbbbbbb
a2[b] --> abb
*/
int main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        stack<string> st;
        FOR(i, 0, s.size() - 1)
        {
            string tmp = "", res = "";
            if (s[i] == ']')
            {
                while (!st.empty() && st.top() != "[")
                {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                int x = 1;
                if (!st.empty() && isdigit(st.top()[0]))
                {
                    x = stoi(st.top());
                    st.pop();
                }
                FOR(j, 1, x) res += tmp;
                st.push(res);
            }
            else
            {
                string res = "";
                if(isdigit(s[i]))
                {
                    while(!st.empty() && isdigit(st.top()[0]))
                    {
                        res = res + st.top();
                        st.pop();
                    }
                    st.push(res + s[i]);
                }
                else st.push(res + s[i]);
            }
        }
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}

