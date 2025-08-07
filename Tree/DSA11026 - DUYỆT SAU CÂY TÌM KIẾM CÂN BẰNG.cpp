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

int pre[1000009], n;

void postOrder(node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
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

node* build(int a[], int l, int r)
{
    if(l > r) return NULL;
    int m = (l + r) / 2;
    node* root = makeNode(a[m]);
    root->left = build(a, l, m - 1);
    root->right = build(a, m + 1, r);
    return root;
}

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n;
        FOR(i, 1, n)
        {
            cin >> pre[i];
        }
        sort(pre + 1, pre + n + 1);
        node* root = build(pre, 1, n);
        postOrder(root);
        cout << endl;
        delete root;
    }
    return 0;
}