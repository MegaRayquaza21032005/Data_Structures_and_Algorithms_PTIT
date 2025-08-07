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
    int data;
    node *left, *right;
};

node* makeNode(int x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void makeRoot(node *root, int u, int v, int c)
{
    if(c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}

void insertNode(node* root, int u, int v, int c)
{
    if(root == NULL) return;
    else if(root->data == u)
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front(); q.pop();
        cout << top->data << " ";
        if(top->left != NULL) q.push(top->left);
        if(top->right != NULL) q.push(top->right);
    }
}
void spiralOrder(node* root)
{
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            node* top = st1.top(); st1.pop();
            cout << top->data << " ";
            if(top->right != NULL) st2.push(top->right);
            if(top->left != NULL) st2.push(top->left);
        }
        while(!st2.empty())
        {
            node* top = st2.top(); st2.pop();
            cout << top->data << " ";
            if(top->left != NULL) st1.push(top->left);
            if(top->right != NULL) st1.push(top->right);
        }
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        node *root = NULL;
        int n, u, v; cin >> n;
        FOR(i, 1, n)
        {
            char c;
            cin >> u >> v >> c;
            if(root == NULL)
            {
                root = makeNode(u);
                makeRoot(root, u, v, c);
            }
            else insertNode(root, u, v, c);
        }
        spiralOrder(root);
        cout << endl;
        delete root;
    }
    return 0;
} 