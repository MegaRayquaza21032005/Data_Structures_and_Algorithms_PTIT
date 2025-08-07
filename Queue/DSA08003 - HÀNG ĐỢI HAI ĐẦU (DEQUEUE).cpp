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


int main()
{
    fast;
    int T; cin >> T;
    deque<int> dq;
    while(T--)
    {
        string s; cin >> s;
        if(s == "PUSHBACK")
        {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(s == "PUSHFRONT")
        {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if(s == "PRINTFRONT")
        {
            if(dq.empty() == false)
            {
                cout << dq.front() << endl;
            }
            else cout << "NONE" << endl;
        }
        else if(s == "PRINTBACK")
        {
            if(dq.empty() == false)
            {
                cout << dq.back() << endl;
            }
            else cout << "NONE" << endl;
        }
        else if(s == "POPBACK")
        {
            if(!dq.empty())
            {
                dq.pop_back();
            }
        }
        else if(s == "POPFRONT")
        {
            if(!dq.empty())
            {
                dq.pop_front();
            }
        }
    }
    return 0;
} 