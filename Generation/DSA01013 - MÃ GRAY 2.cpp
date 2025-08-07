#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
int b[1009];

string convert(int res)
{
    string s = "";
    while(res != 0)
    {
        if(res % 2 == 0) s += "0";
        else s += "1";
        res /= 2;
    }
    reverse(s.begin(), s.end());
    while(s.size() < n) s = "0" + s;
    return s;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        vector<string> v;
        int i = 0;
        string t;
        cin >> t;
        n = t.size();
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
            v.push_back(q.front());
            q.pop();
        }
        int res = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] == t) res = i;
        }
        cout << convert(res) << endl;
    }
    return 0;
}