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

int levelOrder(node* root)
{
    int M = -1;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        node* ptr = q.front().first;
        int lv = q.front().second;
        q.pop();
        if(ptr->left == NULL && ptr->right == NULL)
        {
            if(M == -1) M = lv;
            else
            {
                if(M != lv) return 0;
            }
        }
        if(ptr->left != NULL)
        {
            if(ptr->right == NULL) return 0;
            q.push({ptr->left, lv + 1});
        }
        if(ptr->right != NULL)
        {
            if(ptr->left == NULL) return 0;
            q.push({ptr->right, lv + 1});
        }
    }
    return 1;
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
        if(levelOrder(root)) cout << "Yes\n";
        else cout << "No\n";
        delete root;
    }
    return 0;
}