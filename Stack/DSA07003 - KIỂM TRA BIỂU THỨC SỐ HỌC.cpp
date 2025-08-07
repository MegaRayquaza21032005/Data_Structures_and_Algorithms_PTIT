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
((a+b)) --> ((+))

(a + (b)/c) --> (+()/)

(a + b*(c-d)) --> (+*(-))
*/
int main()
{
    fast;
    int T; cin >> T;
    cin.ignore();
    stack<char> st;
    while(T--)
    {
        string s; getline(cin, s);
        int check = 0;
        FOR(i, 0, s.size() - 1)
        {
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') st.push(s[i]);
            else if(s[i] == ')')
            {
                if(st.top() == '(')
                {
                    cout << "Yes\n";
                    check = 1;
                    break;
                }
                else
                {
                    while(st.top() != '(') st.pop();
                    st.pop();
                }
            }
        }
        if(check == 0) cout << "No\n";
    }
    return 0;
}