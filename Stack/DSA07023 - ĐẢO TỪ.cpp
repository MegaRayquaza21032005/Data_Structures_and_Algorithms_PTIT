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
    cin.ignore();
    while(T--)
    {
        string s; 
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            st.push(word);
        }
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}