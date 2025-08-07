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

/*
Ý tưởng:
Dãy ngoặc đúng thỏa mãn 2 điều kiện:

    Tổng số ngoặc mở '(' bằng số ngoặc đóng ')'.

    Tại bất kỳ vị trí nào khi duyệt từ trái sang phải, số dấu '(' không được ít hơn ')'.

    Nếu có ) mà không có ( ==> cái dấu đó phải đảo chiều ==> tăng res
*/
int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        stack<char> st;
        int res = 0;
        for(char x : s)
        {
            if(x == '(')
            {
                st.push(x);
            }
            else
            {
                if(st.empty())
                {
                    res++;
                    st.push('(');
                }
                else st.pop();
            }
        }
        res += st.size() / 2;
        cout << res << endl;
    }
    return 0;
}