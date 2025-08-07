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
Ý tưởng: na ná bài 07009
*/
int main()
{
    fast;
    int T; cin >> T;
    stack<string> st;
    while(T--)
    {
        string s; cin >> s;
        FORD(i, s.size() - 1, 0)
        {
            string tmp = "";
            if(isalpha(s[i])) st.push(tmp + s[i]);
            else
            {
                string x = st.top(); st.pop();
                string y = st.top(); st.pop();
                tmp += x + y + s[i];
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}