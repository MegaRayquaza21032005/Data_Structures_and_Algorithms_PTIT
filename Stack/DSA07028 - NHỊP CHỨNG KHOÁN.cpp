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
    stack<int> st;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n), l(n);
        FOR(i, 0, n - 1) cin >> a[i];

        st.push(0);
        l[0] = -1;
        FOR(i, 1, n - 1)
        {
            while(!st.empty() && a[i] >= a[st.top()]) st.pop();
            if(st.empty()) l[i] = -1;
            else l[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        FOR(i, 0, n - 1)
        {
            cout << i - l[i] << " ";
        }
        cout << endl;
    }
    return 0;
}