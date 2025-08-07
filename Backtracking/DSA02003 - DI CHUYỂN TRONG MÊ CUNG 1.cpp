#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int a[1009][1009], n, k, check = 0;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
string dc[2] = {"D", "R"};
string s = "";

void input(int a[][1009], int n)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    }
}
void Try(int i, int j)
{
    a[i][j] = 0;
    for(int k = 0; k < 2; ++k)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= n && a[i1][j1] == 1)
        {
            s += dc[k];
            if(i1 == n && j1 == n)
            {
                cout << s << " ";
                check = 1;
            }
            else Try(i1, j1);
            s.pop_back();
        }
    }
    a[i][j] = 1;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        check = 0;
        cin >> n;
        input(a, n);
        if(a[1][1] == 0) cout << -1 << endl;
        else
        {
            Try(1, 1);
            if(check == 0) cout << -1 << endl;
        }
        cout << endl;
    }
}