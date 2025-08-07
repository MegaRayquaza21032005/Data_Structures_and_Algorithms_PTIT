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

int a[1009], n, k, test = 0;
string res = ""; 
//vector<string> v;
bool check(string s)
{
    //int a = stoi(s.substr(0, 2)), b = stoi(s.substr(5, 2)), c = stoi(s.substr(10, 2));
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[5] - '0') * 10 + (s[6] - '0');
    int c = (s[10] - '0') * 10 + (s[11] - '0');
    if(s[3] == '+') return (a + b) == c;
    else return (a - b) == c;
}

void Try(int i, string s)
{
    if(test) return;
    if(i >= n)
    {
        if(check(s))
        {
            test = 1;
            res = s;
        }
        return;
    }
    if(s[i] != '?')
    {
        Try(i + 1, s);
    }
    else if(i == 3)
    {
        s[i] = '+';
        Try(i + 1, s);
        s[i] = '-';
        Try(i + 1, s);
    }
    else if(i == 0 || i == 5 || i == 10)
    {
        for(char j = '1'; j <= '9'; ++j)
        {
            s[i] = j;
            Try(i + 1, s);
        }
    }
    else
    {
        for(char j = '0'; j <= '9'; ++j)
        {
            s[i] = j;
            Try(i + 1, s);
        }
    }

}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    cin.ignore();
    while(T--)
    {
        test = 0;
        res = "";
        string s;
        getline(cin, s);
        n = s.size();
        if(s[3] == '*' || s[3] == '/') cout << "WRONG PROBLEM!" << endl;
        else
        {
            Try(0, s);
            if(res != "") cout << res << endl;
            else cout << "WRONG PROBLEM!" << endl;
        }
    }
}