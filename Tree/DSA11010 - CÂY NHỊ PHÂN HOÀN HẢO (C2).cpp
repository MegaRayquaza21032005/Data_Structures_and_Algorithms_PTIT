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
    node* left, *right;
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
    if(c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}

void insertNode(node* root, int u, int v, char c)
{
    if(root == NULL) return;
    else if(root->data == u) makeRoot(root, u, v, c);
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

int height(node* root)
{
    if(root == NULL) return 0;
    else return 1 + max(height(root->left), height(root->right));
}

bool check(node* root, int lv, int h)
{
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL && h != lv) return false;
    else if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) return false;
    else
    {
        return check(root->left, lv + 1, h) && check(root->right, lv + 1, h); 
    }
    return true;
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
        int h = height(root) - 1;
        if(check(root, 0, h)) cout << "Yes\n";
        else cout << "No\n";
        delete root;
    }
    return 0;
} 