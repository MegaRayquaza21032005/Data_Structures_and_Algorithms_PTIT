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

int n;
vector<int> pre;

void inOrder(node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void preOrder(node* root)
{
    if(root != NULL)
    {
        pre.pb(root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
node* insert(node* root, int key)
{
    if(root == NULL) return makeNode(key);
    else if(root->data > key) 
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}


int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, u, v; char c;
        cin >> n;
        node* root = NULL;
        while(n--)
        {
            cin >> u >> v >> c;
            if(root == NULL)
            {
                root = makeNode(u);
                makeRoot(root, u, v, c);
            }
            else insertNode(root, u, v, c);
        }
        preOrder(root);
        node* root1 = NULL;
        for(int x : pre)
        {
            root1 = insert(root1, x);
        }
        inOrder(root1);
        cout << endl;
        delete root, root1;
        pre = {};
    }
    return 0;
}