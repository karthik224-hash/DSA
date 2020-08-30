//Level Order Traversal
//Link: https://www.hackerrank.com/contests/smart-interviews/challenges/si-level-order-of-tree

//In Binary Search Trees we have one Level Order Traversal, but here we use only one queue
void levelOrder(node *root) 
{ 
    if (root == NULL) return; 

    // Create an empty queue for 
    // level order tarversal 
    queue<node *> q; 
      
    // to store front element of  
    // queue. 
    node *curr; 
  
    // Enqueue Root and NULL node. 
    q.push(root); 
    q.push(NULL); 
  
    while (q.size() > 1) 
    { 
        curr = q.front(); 
        q.pop(); 
          
        // condition to check  
        // occurrence of next  
        // level. 
        if (curr == NULL) 
        { 
           q.push(NULL); 
           cout << "\n"; 
        } 
          
        else { 
              
            // pushing left child of  
            // current node. 
            if(curr->left) 
            q.push(curr->left); 
              
            // pushing right child of 
            // current node. 
            if(curr->right) 
            q.push(curr->right); 
              
            cout << curr->data << " "; 
        } 
    } 
} 
//Level Order By recursion
void printLevelOrder(node* root)  
{  
    int h = height(root);  //The height fun finds the height of the tree
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  
  
/* Print nodes at a given level */
void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

//Zig-Zag Level Order Traversal
//Link : https://www.hackerrank.com/contests/smart-interviews/challenges/si-zig-zag-level-order-of-tree
void Zig-Zag_LevelOrder(node* root){
    if(!root) return;
    stack<node*> curLvl;
    stack<node*> nxtLvl;
    curLvl.push(root);
    bool leftToRight = 0;
    while(!curLvl.empty()){
        node *curr = curLvl.top();
        curLvl.pop();
            cout<< curr->val <<" ";
            if(leftToRight){
                if(curr->left)
                    nxtLvl.push(curr->left);
                if(curr->right)
                    nxtLvl.push(curr->right);
            }
            else{
                if(curr->right)
                    nxtLvl.push(curr->right);
                if(curr->left)
                    nxtLvl.push(curr->left);
            }
        if(curLvl.empty()){
            leftToRight = !leftToRight;
            swap(curLvl,nxtLvl);
            }
    }
  
    cout<<"\n";
    return;
}

//Bottom up Level Order Traversal
//Link : https://www.hackerrank.com/contests/smart-interviews/challenges/si-bottom-up-level-order-of-tree

//Same as level Order traversal but we push all the elements in stack in the reverse order while doing level order traversal 

void bottomLevelOrder(node* root){
    if(!root) return;
    queue<node*> q;
    stack<int> s;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        node *curr = q.front();
        q.pop();
        if(curr==NULL){
            q.push(NULL);
            s.push(-1);
            //cout<<"\n";
        }
        else{
            s.push(curr->val);
            if(curr->right)
                q.push(curr->right); 
            if(curr->left){ 
                q.push(curr->left);
            }
        }
    }
    while(!s.empty()){
        if(s.top()==-1) cout<<"\n";
        else cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return;
}

//Zig-Zag bottom up level order Traversal
//Link: https://www.hackerrank.com/contests/smart-interviews/challenges/si-zig-zag-bottom-up-level-order-of-tree

void Zig-Zag_bottomLevelOrder(node* root){
    bool leftToRight = false;
    if(!root) return;
    stack<node*> curLvl;
    stack<node*> nxtLvl;
    stack<int> s;
    curLvl.push(root);
    while(curLvl.empty()==false){
        node *temp= curLvl.top();
        s.push(temp->val);
        curLvl.pop();
        if(!leftToRight){
            if(temp->left) 
                nxtLvl.push(temp->left);
            if(temp->right)
                nxtLvl.push(temp->right);          
            }
        else{
             if(temp->right)
                nxtLvl.push(temp->right);  
             if(temp->left) 
                nxtLvl.push(temp->left);
        }
        if(curLvl.empty()){
            swap(curLvl,nxtLvl);
            leftToRight=!leftToRight;
        }  
    }        
   
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return;
}

//Vertical level Order Traversal 
//Link: https://www.hackerrank.com/contests/smart-interviews/challenges/si-vertical-order-of-tree

 map<int,set<int>> M;
 
void verticalorder(node* root,int distance){
    if(root==NULL) return;
        verticalorder(root->left,distance-1);
        verticalorder(root->right,distance+1);
        M[distance].insert(root->val);
    }
/* In calling function we can write
      for(auto v: b1.M){
             for(auto i:v.second)
                cout<<i<<" ";
            cout<<"\n";
         }
*/