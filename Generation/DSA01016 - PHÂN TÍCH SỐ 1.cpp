#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ll long long

int n, a[1009], final = 0, cnt = 1;
void ktao()
{
    a[1] = n;
    cnt = 1;
    final = 0;
}
/*
+ tìm từ phải sang trái phần tử != 1 đầu tiên
+ giảm phần tử đó đi 1 dv (gọi là a[i])
+ tìm phần còn thiếu và biểu diễn phần còn thiếu qua a[i];
*/
void sinh()
{
    int i = cnt;  // so phan tu hien tai
    while(i >= 1 && a[i] == 1) --i;
    if(i == 0) final = 1;
    else
    {
        --a[i];
        int d = cnt - i + 1; // phần còn thiếu (do các phần từ bỏ qua toàn số 1 nên phần bị thiếu là cnt - i và + 1 do --a[i])
        cnt = i; // reset lại số phần tử hiện tại
        int q = d / a[i]; // biểu diễn phần còn thiếu qua a[i]
        int r = d % a[i]; // biểu diễn phần còn thiếu qua a[i]
        for(int j = 1; j <= q; ++j)
        {
            cnt++;
            a[cnt] = a[i]; // q số a[i] tiếp theo
        }
        if(r != 0) a[++cnt] = r; // sau khi biểu diễn q số a[i] nhưng vẫn còn phần dư nên điền vào cuối
    }
}
int main() 
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ktao();
        while(!final)
        {
            cout << "(";
            for(int i = 1; i <= cnt; ++i)
            {
                if(i != cnt) cout << a[i] << " ";
                else cout << a[i] << ") ";
            }
            sinh();
        }
        cout << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}