#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;


int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 9), b(n + 9);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a.begin(), a.begin() + n);
        int l = 0, r = n - 1;
        while(a[l] == b[l]) l++;
        while(a[r] == b[r]) r--;
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
 