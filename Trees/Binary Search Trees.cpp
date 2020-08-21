#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

class btree
{
    node *head;

public:
    btree()
    {
        head = NULL;
    }
    node *GetNewNode(int data)
    {
        node *tmp = new node;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->val = data;
        return tmp;
    }
    bool search(int target)
    {
        return search(head, target);
    }
    void insert(int key)
    {
        head = insert(head, key);
    }
    void inorder()
    {
        inorder(head);
        cout << "\n";
    }
    void preorder()
    {
        preorder(head);
        cout << "\n";
    }
    void postorder()
    {
        postorder(head);
        cout << "\n";
    }
    void destroy_tree()
    {
        destroy_tree(head);
    }
    int find_min()
    {
        return find_min(head);
    }
    int find_max()
    {
        return find_max(head);
    }
    int height()
    {
        return height(head);
    }
    void levelOrder()
    {
        levelOrder(head);
    }
    void deleteNode(int key)
    {
        head = deleteNode(head, key);
    }

private:
    bool search(node *root, int key);
    node *insert(node *root, int key);
    void inorder(node *root);
    void preorder(node *root);
    void postorder(node *root);
    void destroy_tree(node *root);
    int find_min(node *root);
    int find_max(node *root);
    int height(node *);
    void levelOrder(node *);
    node *deleteNode(node *head, int key);
};

node *btree::insert(node *root, int key)
{
    if (root == NULL)
    {
        root = GetNewNode(key);
    }
    else if (key <= root->val)
    { //try to always compare with key to avoid confusion
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

bool btree::search(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == key)
        return true;
    else if (key < root->val)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}

node *btree::deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL) //check if it is a leaf node
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = root->right;
            ;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

void btree::inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void btree::preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void btree::postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void btree::levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        queue<node *> tmp(q);
        while (!tmp.empty())
        {
            node *curr = tmp.front(); //TC is O(n)
            cout << curr->val << " "; //here i wrote two loops for printing neatly else we can just use one loop
            tmp.pop();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

void btree::destroy_tree(node *root)
{
    if (root != NULL)
    {
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
    }
}

int btree::find_min(node *root)
{
    if (root->left == NULL)
    {
        return root->val;
    }
    return find_min(root->left);
}

int btree::find_max(node *root)
{
    if (root->right == NULL)
    {
        return root->val;
    }
    return find_max(root->right);
}

int btree::height(node *root)
{

    if (root == NULL)
    {
        return -1;
    }
    int x, y;
    x = height(root->left);
    y = height(root->right);
    return max(x, y) + 1;
}

int main()
{
    btree b1;
    b1.insert(4);
    b1.insert(2);
    b1.insert(3);
    b1.insert(6);
    b1.insert(7);
    b1.insert(5);
    /* b1.inorder();
    b1.preorder();
    b1.postorder();
    cout<<b1.find_min()<<"\n";
    cout<<b1.find_max()<<"\n"; 
    cout<<b1.height()<<"\n"; */
    //b1.levelOrder();
    b1.deleteNode(6);
    b1.levelOrder();
    b1.destroy_tree();
}