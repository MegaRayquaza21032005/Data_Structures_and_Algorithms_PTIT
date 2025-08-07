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
Ý tưởng: phần tử lớn nhất của dãy phía trước < phần tử nhỏ nhất ở dãy phía sau --> đúng
*/
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n;
        int a[n + 9];
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        int M[n + 9], m[n + 9];
        // M[i]: giá trị lớn nhất từ 1 đến i
        // m[i]: giá trị nhỏ nhất từ i đến n
        // M[i] <= n[i + 1] --> True
        M[1] = a[1];
        m[n] = a[n];
        FOR(i, 2, n) M[i] = max(M[i - 1], a[i]);
        FORD(i, n - 1, 1) m[i] = min(m[i + 1], a[i]);
        vector<int> v;
        FOR(i, 1, n - 1)
        {
            if(M[i] <= m[i + 1])
            {
                v.pb(i);
            }
        }
        if(v.size() == 0)
        {
            cout << 0 << endl << endl;
        }
        else
        {
            cout << v.size() << endl;
            for(auto x : v)
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }
}
 