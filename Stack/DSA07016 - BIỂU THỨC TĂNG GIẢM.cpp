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
Sử dụng ngăn xếp (stack) để xây dựng số theo quy tắc sau:

    Duyệt từng ký tự của chuỗi:

    Tại mỗi bước i, đưa số i+1 vào stack.

Khi gặp:

    'I' hoặc cuối chuỗi:

    Lấy toàn bộ các phần tử trong stack ra (pop) và thêm vào chuỗi kết quả.

Vì stack là LIFO (Last In First Out), nên khi pop ra sẽ tạo được thứ tự giảm dần nếu chuỗi là 'D'
*/
int main()
{
    fast;
    int T; cin >> T;
    stack<int> st;
    string res = "";
    while(T--)
    {
        res = "";
        string s; cin >> s;
        FOR(i, 0, s.size() - 1)
        {
            st.push(i + 1);
            if(s[i] == 'I')
            {
                while(!st.empty())
                {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(s.size() + 1);
        while(!st.empty())
        {
            res += to_string(st.top());
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}