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

bool check(node* root, node* root1)
{
    if(root == NULL && root1 == NULL) return true;
    if(root != NULL && root1 != NULL)
    {
        return (root->data == root1->data) && check(root->left, root1->left) && check(root->right, root1->right);
    }
    return false;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int u, v; char c;
        node* root = NULL;
        FOR(i, 1, n)
        {
            cin >> u >> v >> c;
            if(root == NULL)
            {
                root = makeNode(u);
                makeRoot(root, u, v, c);
            }
            else insertNode(root, u, v, c);
        }
        int m; cin >> m;
        node* root1 = NULL;
        FOR(i, 1, m)
        {
            cin >> u >> v >> c;
            if(root1 == NULL)
            {
                root1 = makeNode(u);
                makeRoot(root1, u, v, c);
            }
            else insertNode(root1, u, v, c);
        }
        cout << check(root, root1) << endl;
        delete root, root1;
    }
    return 0;
}