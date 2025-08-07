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

int a[1009], n, k, test = 0, res = INT_MAX;
string s[1009];

int process()
{
    int m = INT_MAX, M = INT_MIN, tmp;
    string num = "";
    FOR(i, 1, n)
    {
        num = "";
        FOR(j, 0, k - 1)
        {
            num += s[i][a[j]];
        }
        tmp = stoi(num);
        m = min(m, tmp);
        M = max(M, tmp);
    }
    return M - m;
}
int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        res = INT_MAX;
        cin >> n >> k;
        FOR(i, 1, n)
        {
            cin >> s[i];
        }
        FOR(i, 0, k - 1) a[i] = i;
        do
        {
            res = min(res, process());
        } 
        while (next_permutation(a, a + k));
        cout << res << endl;
    }
}
/*
Giải thích đề bài:
Bài toàn yêu cầu sử dụng 1 hoán vị, áp dụng hoán vị đó lên tất cả các chữ số và tìm min delta giữa số lớn nhất và nhỏ nhất
ví dụ:
3 3
010
909
012

áp dụng hoán vị 1 3 2:
001
990
021
-->989

áp dụng hoán vị 2 1 3
100
099
102
--> 3 (kết quả bài toán)
*/