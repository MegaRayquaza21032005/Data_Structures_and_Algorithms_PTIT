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
const ll llmod = 1e15 + 7;


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
const ll llmod = 1e15 + 7;

int dp[1000009];
int process(int s, int t)
{
    if(s >= t) return s - t;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int tmp = q.front(); q.pop();
        if(tmp == t) return dp[tmp];
        if(tmp * 2 < t * 2 && dp[tmp * 2] == 0) // tmp < t mới nhân đôi, tmp > t thì chỉ cần trừ đến khi nào = t
        {
            dp[tmp * 2] = dp[tmp] + 1;
            q.push(tmp * 2);
        }
        if(dp[tmp - 1] == 0)
        {
            dp[tmp - 1] = dp[tmp] + 1;
            q.push(tmp - 1);
        }
    }
    return -1;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int s, t; cin >> s >> t;
        cout << process(s, t) << endl;
        ms(dp, 0);
    }
    
    return 0;
}
// map<int, int> dp;
// int process(int s, int t)
// {
//     if(s >= t) return s - t;
//     queue<int> q;
//     q.push(s);
//     while(!q.empty())
//     {
//         int tmp = q.front(); q.pop();
//         if(tmp == t) return dp[tmp];
//         if(tmp * 2 < t * 2 && dp[tmp * 2] == 0)
//         {
//             dp[tmp * 2] = dp[tmp] + 1;
//             q.push(tmp * 2);
//         }
//         if(dp[tmp - 1] == 0)
//         {
//             dp[tmp - 1] = dp[tmp] + 1;
//             q.push(tmp - 1);
//         }
//     }
//     return -1;
// }
// int main()
// {
//     fast;
//     int T = 1;
//     cin >> T;
//     while(T--)
//     {
//         int s, t; cin >> s >> t;
//         cout << process(s, t) << endl;
//         dp = {};
//     }
    
//     return 0;
// }