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

int a[1000009];
ll merge(int a[], int l, int r, int m)
{
    vector<int> left(a + l, a + m + 1);
    vector<int> right(a + m + 1, a + r + 1);
    int i = 0, j = 0, dem = l;
    ll cnt = 0;
    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            a[dem++] = left[i++];
            cnt += j;
        }
        else
        {
            a[dem++] = right[j++];
        }
    }
    while(i < left.size())
    {
        a[dem++] = left[i++];
        cnt += j;
    }
    while(j < right.size()) a[dem++] = right[j++];
    return cnt;
}

ll merge_sort(int a[], int l, int r)
{
    if(l == r) return 0;
    else
    {
        int m = (l + r) / 2;
        return merge_sort(a, l, m) + merge_sort(a, m + 1, r) + merge(a, l, r, m);
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        cout << merge_sort(a, 1, n) << endl;
    }
    return 0;
}