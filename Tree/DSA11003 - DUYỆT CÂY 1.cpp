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

/*
Trong Preorder, node đầu tiên luôn là gốc cây (root).

Tìm vị trí node đó trong Inorder.
    → Từ đó chia được thành cây con trái và cây con phải.

Đệ quy tiếp tục với mảng con trái và phải.
*/
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

node* buildTree(int in[], int pre[], int inStart, int inEnd, int &preIndex, unordered_map<int, int> mp)
{
    if(inStart > inEnd) return NULL;
    int cur_node = pre[preIndex]; // data của node root hiện tại
    ++preIndex;
    node* ptr = makeNode(cur_node);
    if(inStart == inEnd) return ptr;
    int inIndex = mp[cur_node]; // vị trí của node root hiện tại trong in[] --> 
    //bên trái inIndex là cây con bên trái, bên phải inIndex là cây con bên phải --> 
    //đệ quy đến 2 bên để tìm root của 2 cây con đó
    ptr->left = buildTree(in ,pre, inStart, inIndex - 1, preIndex, mp);
    ptr->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex, mp);
    return ptr;
}

void postOrder(node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int in[n + 9], pre[n + 9];
        FOR(i, 1, n) cin >> in[i];
        FOR(i, 1, n) cin >> pre[i];
        unordered_map<int, int> mp; // lưu vị trí phần tử của pre[] trong in[]
        FOR(i, 1, n) mp[in[i]] = i;
        int preIndex = 1; // chỉ số của pre[] --> duy trì root
        node* root = buildTree(in, pre, 1, n, preIndex, mp);
        postOrder(root);
        cout << endl;
    }
    return 0;
}