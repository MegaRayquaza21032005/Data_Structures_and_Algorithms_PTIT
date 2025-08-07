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
int in[1000009], lv[1000009], n;


void postOrder(node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

node* build_tree(int in[], int lv[], int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if(inStart > inEnd) return NULL;
    int inIdx;
    FOR(i, 1, n) // duyệt qua lv[] tìm root của nhánh đó
    {
        int pos = mp[lv[i]];
        if(pos >= inStart && pos <= inEnd)
        {
            inIdx = pos;
            break;
        }
    }
    node* cur = makeNode(in[inIdx]);
    if(inStart == inEnd) return cur;
    else
    {
        cur->left = build_tree(in, lv, inStart, inIdx - 1, mp);
        cur->right = build_tree(in, lv, inIdx + 1, inEnd, mp);
    }
    return cur;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> in[i];
        FOR(i, 1, n) cin >> lv[i];
        unordered_map<int, int> mp; // lưu vị trí phần tử của pre[] trong in[]
        FOR(i, 1, n) mp[in[i]] = i;
        node* root = build_tree(in, lv, 1, n, mp);
        postOrder(root);
        cout << endl;
        delete root;
    }
    return 0;
}