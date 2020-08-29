//Here We try to imitate the recursive process iteratively

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Inorder Traversal
void inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s; //stack is used to store nodes as recursion stack stores
    while (1)
    {
        if (root)
        {
            s.push(root); //go left of the tree as long as you find null(leaf), by pushing every node along the way into stack
            root = root->left;
        }
        else
        {
            if (s.empty())
                break; //if stack is empty whole tree is traversed
            root = s.top();
            s.pop();
            cout << root->val << " "; //print the current element and go to right side
            root = root->right;
        }
    }
}

//Pre Order Traversal
// Traversal is same as inorder just the print statement is different
void PreOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> s; //stack is used to store nodes as recursion stack stores
    while (1)
    {
        if (root)
        {
            cout << root->val << " "; //print the current element and go to right side
            s.push(root);             //go left of the tree as long as you find null(leaf), by pushing every node along the way into stack
            root = root->left;
        }
        else
        {
            if (s.empty())
                break; //if stack is empty whole tree is traversed
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

//Post Order Traversal
//Do preOrder Traversal and store it in a list and reverse the list
void PostOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    stack<int> res;
    while (1)
    {
        if (root)
        {
            res.push(root->val);
            s.push(root); //go left of the tree as long as you find null(leaf), by pushing every node along the way into stack
            root = root->left;
        }
        else
        {
            if (s.empty())
                break; //if stack is empty whole tree is traversed
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    //instead of stack we can also use the vector and reverse it at the end
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
}