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
    for(int i = 1; i <= n; ++i) a[i] = 0;
}
void generate()
{
    int i = n;
    while(a[i] == 1 && i >= 1)
    {
        a[i] = 0;
        --i;
    }
    if(i == 0) final = 1;
    else a[i] = 1;
}
bool check(int a[], int n, int k)
{
    int cnt1 = 0, cnt2 = 0;
    a[n + 1] = 100;
    for(int i = 1; i <= n + 1; ++i)
    {
        if(a[i] == 0) cnt1++;
        else
        {
            if(cnt1 == k) cnt2++;
            cnt1 = 0;
        }
    }
    if(cnt2 == 1) return true;
    else return false;
}
int main()
{
    fast;
    cin >> n >> k;
    vector<string> v;
    init();
    while(!final)
    {
        if(check(a, n, k))
        {
            string s = "";
            for(int i = 1; i <= n; ++i)
            {
                if(a[i] == 0) s += "A";
                else s += "B";
            }
            v.push_back(s);
        }
        generate();
    }
    cout << v.size() << endl;
    for(string x : v) cout << x << endl;
    return 0;
}
