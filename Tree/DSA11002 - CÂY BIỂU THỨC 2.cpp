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
const ll llmod = 1e15 + 7;

struct node
{
    ll data;
    node *left, *right;
};

node* makeNode(ll x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
ll calculator(int x, int y, string c)
{
    if(c == "+") return x + y;
    else if(c == "-") return x - y;
    else if(c == "*") return x * y;
    else return x / y;
}
int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
        vector<string> v;
        int n; cin >> n;
        FOR(i, 1, n)
        {
            string s; cin >> s;
            v.pb(s);
        }
        queue<node*> st;
        FORD(i, v.size() - 1, 0)
        {
            if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
            {
                node *x = st.front(); st.pop();
                node *y = st.front(); st.pop();
                node *tmp = makeNode(calculator(y->data, x->data, v[i]));
                st.push(tmp);
            }
            else
            {
                st.push(makeNode(stoll(v[i])));
            }
        }
        cout << st.front() -> data << endl;
    }
    return 0;
} 