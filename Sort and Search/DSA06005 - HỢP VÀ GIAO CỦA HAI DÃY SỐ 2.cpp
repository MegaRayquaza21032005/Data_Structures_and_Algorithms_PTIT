#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;


int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        set<int> se1, se2;
        set<int> Union, Intersection;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            se1.insert(x);
            Union.insert(x);
        }
        for(int i = 0; i < m; ++i)
        {
            int x; cin >> x;
            se2.insert(x);
            Union.insert(x);
        }
        for(auto x : se1)
        {
            if(se2.find(x) != se2.end()) Intersection.insert(x);
        }
        for(auto x : Union) cout << x << " ";
        cout << endl;
        for(auto x : Intersection) cout << x << " ";
        cout << endl;
    }
    return 0;
}
 