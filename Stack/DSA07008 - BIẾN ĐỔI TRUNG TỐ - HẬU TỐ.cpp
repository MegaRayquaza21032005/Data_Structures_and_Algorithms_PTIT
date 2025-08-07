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
Duyệt từng ký tự của chuỗi:

    Nếu là toán hạng (A–Z, a–z) → đưa thẳng vào kết quả.

    Nếu là dấu mở ngoặc ( → đẩy vào stack.

    Nếu là dấu đóng ngoặc ) → pop toàn bộ toán tử khỏi stack cho đến khi gặp (.

    Nếu là toán tử (+, -, *, /, ^):

    ==> So sánh độ ưu tiên với toán tử trên đỉnh stack:

        Nếu stack.top() ưu tiên cao hơn hoặc bằng, thì pop ra khỏi stack và thêm vào kết quả.

        Sau đó, push toán tử hiện tại lên stack.

        Sau khi duyệt xong, pop hết các phần còn lại trong stack (trừ () vào kết quả.

(B*C+A) --> BC*A+ chứ ko phải BCA+*
*/

int degree(char c)
{
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}
int main()
{
    fast;
    int T; cin >> T;
    stack<char> st;
    while(T--)
    {
        string s; cin >> s;
        string res = "";
        FOR(i, 0, s.size() - 1)
        {
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                if(st.empty()) st.push(s[i]);
                else if(degree(s[i]) > degree(st.top())) st.push(s[i]);
                else
                {
                    while(!st.empty() && degree(st.top()) >= degree(s[i]))
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            else if(s[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else res += s[i];
        }
        while(!st.empty())
        {
            if(st.top() != '(') res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}