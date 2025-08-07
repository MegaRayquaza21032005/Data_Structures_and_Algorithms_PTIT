#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int x[1009], n, k, cnt = 0;
int col[1009];
int main_diagnoal[1009];
int sub_diagnoal[1009];

void Try(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        if(col[j] == 0 && main_diagnoal[i - j + n] == 0 && sub_diagnoal[i + j - 1] == 0)
        {
            x[i] = j;
            col[j] = 1;
            main_diagnoal[i - j + n] = 1;
            sub_diagnoal[i + j - 1] = 1;
            if(i == n)
            {
                cnt++;
                // for(int k = 1; k <= n; ++k) cout << x[k] << " ";
                // cout << endl;
            }
            else Try(i + 1);
            col[j] = 0;
            main_diagnoal[i - j + n] = 0;
            sub_diagnoal[i + j - 1] = 0;
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
        cnt = 0;
        Try(1);
        cout << cnt << endl;
    }
}
 