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
    int n; cin >> n;
    stack<int> st;
    FOR(i, 1, n)
    {
        string s; cin >> s;
        if(s == "PUSH")
        {
            int x; cin >> x;
            st.push(x);
        }
        else if(s == "POP")
        {
            if(!st.empty()) st.pop();
        }
        else
        {
            if(!st.empty()) cout << st.top() << endl;
            else cout << "NONE\n";
        }
    }
    return 0;
}