#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        cin.ignore();
        vector<vector<int>> ke(v + 9);
        for (int i = 1; i <= v; ++i)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            string number;
            while (ss >> number)
            {
                ke[i].push_back(stoi(number));
            }
        }
        for (int i = 1; i <= v; ++i)
        {
            sort(ke[i].begin(), ke[i].end());
            // for (int x : ke[i])
            //     cout << x << " ";
            // cout << endl;
        }
        for(int i = 1; i <= v; ++i)
        {
            for(int x : ke[i])
            {
                if(x > i) cout << i << " " << x << endl; 
            }
        }
    }
}