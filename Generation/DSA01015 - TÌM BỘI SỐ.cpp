#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, s, final = 0;
int b[1009];
void init()
{
    for(int i = 1; i <= k; ++i) a[i] = i;
}
void generate()
{
    int i = k;
    while(a[i] == n - k + i && i >= 1)
    {
        --i;
    }
    if(i == 0) final = 1;
    else
    {
        a[i]++;
        for(int j = i + 1; j <= k; ++j)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<ll> q;
        //q.push("0");
        q.push(9);
        if(9 % n == 0) cout << 9 << endl;
        else
        {
            while(true)
            {
                ll tmp = q.front();
                q.pop();
                tmp = tmp * 10;
                if(tmp % n == 0)
                {
                    cout << tmp << endl;
                    break;
                }
                q.push(tmp);
                tmp += 9;
                if(tmp % n == 0)
                {
                    cout << tmp << endl;
                    break;
                }
                q.push(tmp);
            }
        }
        while(q.empty() == 0) q.pop();
    }
    return 0;
}
