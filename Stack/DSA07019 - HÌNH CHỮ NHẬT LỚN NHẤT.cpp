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
Ứng dụng DSA 07027
Từ một cột, tìm VỊ TRÍ phần tử nhỏ hơn nó đầu tiên bên phải và bên trái --> tính được chiều dài hcn
ví dụ:
7
6 2 5 4 5 1 6
số 4 có vị trí đầu tiên nhở hơn nó về bên trái là i = 1 (a[1] = 2) và về bên phải là i = 5 (a[5] = 1)
--> diện tích hcn có chiều cao bằng 4 và chiều dài là (5 - 1 - 1 = 3) là 12 (gồm các cột 5 4 5)
*/
int main()
{
    fast;
    int T; cin >> T;
    stack<int> st;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n), l(n), r(n);
        FOR(i, 0, n - 1) cin >> a[i];
        // Tìm vị trí phần từ đầu tiên nhỏ hơn nó về bên trái
        st.push(0);
        l[0] = -1;
        FOR(i, 1, n - 1)
        {
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            if(st.empty()) l[i] = -1;
            else l[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        // Tìm vị trí phần tử đầu tiên nhỏ hơn nó về bên phải
        st.push(n - 1);
        r[n - 1] = n;
        FORD(i, n - 2, 0)
        {
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            if(st.empty()) r[i] = n;
            else r[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        ll M = INT_MIN;
        FOR(i, 0, n - 1)
        {
            ll s = 1ll * a[i] *(r[i] - l[i] - 1);
            M = max(M, s);
        }
        cout << M << endl;
    }
    return 0;
}