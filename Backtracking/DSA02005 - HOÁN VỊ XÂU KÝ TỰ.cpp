#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int x[1009], n, k, cnt = 0, check = 0;
int used[1009];
string s = "";

void Try(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        if(used[j] == 0)
        {
            x[i] = j;
            used[j] = 1;
            if(i == n)
            {
                for(int k = 1; k <= n; ++k) cout << s[x[k]] << "";
                cout << " ";
            }
            else Try(i + 1);
            used[j] = 0;
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
        cin >> s;
        n = s.size();
        s = "@" + s;
        Try(1);
        cout << endl;
    }
}
 