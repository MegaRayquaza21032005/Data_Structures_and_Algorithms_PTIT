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

int n, k, a[1009], sum = 0, cnt = 0;
int mark[1009];

bool check(int a[], int n)
{
    FOR(i, 2, n)
    {
        if(abs(a[i] - a[i - 1]) < 2) return false;
    }
    return true;
}
void Try(int i)
{
    if(i == n + 1)
    {
        //if(check(a, n) == true)
        {
            FOR(j, 1, n) cout << a[j];
            cout << endl;
        }
    }
    else
    {
        FOR(j, 1, n)
        {
            if(mark[j] == 0)
            {
                if(abs(j - a[i - 1]) >= 2)
                {
                    a[i] = j;
                    mark[j] = 1;
                    Try(i + 1);
                    mark[j] = 0;
                }
            }
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
        cin >> n;
        a[0] = -1;
        Try(1);
        cout << endl;
    }
}