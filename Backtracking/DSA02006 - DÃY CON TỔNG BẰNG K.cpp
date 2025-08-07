#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int n, k, a[1009], check = 0;
int used[1009];
vector<vector<int>> res;
vector<int> tmp;

void Try(int i, int sum = 0)
{
    if(i > n || sum >= k)
    {
        if(sum == k)
        {
            check = 1;
            for(int i = 0; i < tmp.size(); ++i)
            {
                if(i == 0) cout << "[";
                cout << tmp[i];
                if(i == tmp.size() - 1)
                {
                    cout << "] ";
                }
                else cout << " ";
            }
        }
        return;
    }
    else
    {
        for(int j = 1; j >= 0; --j)
        {
            sum += j * a[i];
            if(j == 1) tmp.pb(a[i]);
            Try(i + 1, sum);
            sum -= j * a[i];
            if(j == 1) tmp.pop_back();
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        check = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 0);
        if(check == 0) cout << -1;
        cout << endl;
    }
}