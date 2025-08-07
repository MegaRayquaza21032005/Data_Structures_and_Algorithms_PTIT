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


int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        int k;
        string s;
        cin >> k >> s;
        FOR(i, 0, s.size() - 1)
        {
            if(k == 0) break;
            char maxx_c = s[i];
            int maxx_index = i;
            FORD(j, s.size() - 1, i + 1)
            {
                if(s[j] > maxx_c)
                {
                    maxx_c = s[j];
                    maxx_index = j;
                }
            }
            if(maxx_index != i)
            {
                swap(s[i], s[maxx_index]);
                --k;
            }
        }
        cout << s << endl;
    }
}
 