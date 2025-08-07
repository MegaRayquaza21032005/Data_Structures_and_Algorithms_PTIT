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

int n, k, a[1009][1009], sum = 0, max_sum = 0;
int col[1009], cheo1[1009], cheo2[1009];

void input()
{
    FOR(i, 1, 8)
    {
        FOR(j, 1, 8)
        {
            cin >> a[i][j];
        }
    }
}
void Try(int i, int sum)
{
    FOR(j, 1, 8)
    {
        if(col[j] == 0 && cheo1[i - j + 8] == 0 && cheo2[i + j - 1] == 0)
        {
            col[j] = 1;
            cheo1[i - j + 8] = 1;
            cheo2[i + j - 1] = 1;
            if(i == 8)
            {
                max_sum = max(max_sum, sum + a[i][j]);
            }
            else Try(i + 1, sum + a[i][j]);
            col[j] = 0;
            cheo1[i - j + 8] = 0;
            cheo2[i + j - 1] = 0;
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    int test = 1;
    while(T--)
    {
        max_sum = 0;
        input();
        Try(1, 0);
        cout << "Test " << test << ": ";
        test++;
        cout << max_sum << endl;
    }
}