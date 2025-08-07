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
    char data;
    node *left, *right;
};

node* makeNode(char x)
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
int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        stack<node*> st;
        FOR(i, 0, s.size() - 1)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                node *x = st.top(); st.pop();
                node *y = st.top(); st.pop();
                node *tmp = makeNode(s[i]);
                tmp->right = x;
                tmp->left = y;
                st.push(tmp);
            }
            else
            {
                st.push(makeNode(s[i]));
            }
        }
        inorder(st.top());
        cout << endl;
    }
    return 0;
} 