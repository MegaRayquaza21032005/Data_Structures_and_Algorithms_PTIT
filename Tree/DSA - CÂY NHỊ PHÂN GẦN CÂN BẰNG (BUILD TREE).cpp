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

int a[1000009], n;
struct node
{
    int data;
    node *left, *right;
};

node* makeNode(int x)
{
    node* newNode = new node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void makeRoot(node* root, int u, int v, char c)
{
    if(c == 'L') root->left = makeNode(u);
    else root->right = makeNode(u);
}

void insertNode(node* root, int u, int v, char c)
{
    if(root == NULL) return;
    if(root->data == u) makeRoot(root, u, v, c);
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

node* build_tree(int i)
{
    if(i >= n) return NULL;
    node* root = makeNode(a[i]);
    root->left = build_tree(2 * i + 1);
    root->right = build_tree(2 * i + 2);
    return root;
}

void inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n;
        FOR(i, 0, n - 1) cin >> a[i];
        node* root = build_tree(0);
        inorder(root);
        delete root;
        cout << endl;
    }
    return 0;
} 