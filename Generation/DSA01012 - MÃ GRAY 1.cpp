#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
int b[1009];

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int i = 0;
        cin >> n;
        int cnt = 1;
        queue<string> q;
        q.push("0");
        q.push("1");
        while(true)
        {
            if(cnt >= n) break;
            string tmp = q.front();
            q.pop();
            if(i % 2 == 0)
            {
                q.push(tmp + "0");
                q.push(tmp + "1");
            }
            else
            {
                q.push(tmp + "1");
                q.push(tmp + "0");
            }
            ++i;
            cnt = q.front().size();
        }
        while(q.empty() == 0)
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}