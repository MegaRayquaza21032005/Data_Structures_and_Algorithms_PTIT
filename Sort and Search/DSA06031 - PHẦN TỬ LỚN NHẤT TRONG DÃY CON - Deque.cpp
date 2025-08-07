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
Ý tưởng:
số vào sau mà lớn hơn số vào trước --> số vào trước vô dụng vì nó sẽ ko to nhất --> loại bỏ số vào trước
----> while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
số cần xóa mà ở đầu deque --> xóa nó đi
----> if(dq.front() == i - k) dq.pop_front();
*/
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n + 9);
        FOR(i, 1, n) cin >> a[i];
        deque<int> dq;
        dq.pb(1);
        FOR(i, 2, k) 
        {
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.pb(i);
        }
        cout << a[dq.front()] << " ";
        FOR(i, k + 1, n)
        {
            if(dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.pb(i);
            cout << a[dq.front()] << " ";
        }
        cout << endl;
    }
    return 0;
}
 