/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




// Iterative Solution:- Time Complexity O(n), Space Complexity O(n)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*>st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root= st.top();
            st.pop();
            v.push_back(root->val);
            root=root->right;            
        }
        return v;
    }
};


//Recursive Solution:- Time Complexity O(n), Space Complexity O(n) (function call stack)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return v;
        
    }
    void inorder(TreeNode *root, vector<int>&v){
        if(root==NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
    }
};



//Morris traversal: Time Complexity O(n), Space Complexity O(1). 



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        while(root){
            if(root->left==NULL){
                v.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode *node=root->left;
                while(node->right && node->right!=root){
                    node=node->right;
                }
                if(node->right==NULL){
                    node->right=root;
                    root=root->left;
                }else{
                    node->right=NULL;
                    v.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return v;
        
    }
    
};


// For revision:-
// What is Morris tree traversal?
// We can traverse the tree without using stack or recursion by using Morris Traversal. 
// Morris Traversal is based on the Threaded Binary Tree concept. 
// We build links to Inorder successors and display the data using these links in this traversal,
//  then at the end reverse the changes to restore the original tree.


// What is an Inorder predecessor?
// In the in-order traversal of a binary tree,
//  the predecessor is the node that we traversed before the given node. 
// It's the previous node value before a node in a binary search tree.
