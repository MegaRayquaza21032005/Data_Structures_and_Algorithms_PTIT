#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define pi pair<int, int>
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;


int v, e;
vector<int> ke[1009];
int visited[1009], pos_deg[1009], neg_deg[1009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y;
        cin >> x >> y;
        pos_deg[x]++;
        neg_deg[y]++;
    }
}

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> v >> e;
        input(v, e);
        bool check = true;
        FOR(i, 1, v)
        {
            if(pos_deg[i] != neg_deg[i])
            {
                check = false;
                break;
            }
        }
        cout << check << endl;
        FOR(i, 1, v) ke[i] = {};
        memset(pos_deg, 0, sizeof(pos_deg));
        memset(neg_deg, 0, sizeof(neg_deg));
    }
    return 0;
}