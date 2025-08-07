#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
int b[1009];
void init()
{
    for(int i = 1; i <= n; ++i) cin >> a[i];
}
void generate()
{
    int i = n - 1;
    while(a[i] >= a[i + 1] && i >= 1)
    {
        --i;
    }
    if(i == 0) final = 1;
    else
    {
        int j = n;
        while(a[j] < a[i]) --j;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s; cin >> s;
        cout << n << " ";
        if(next_permutation(s.begin(), s.end())) cout << s << endl;
        else cout << "BIGGEST\n";
    }
    return 0;
}
