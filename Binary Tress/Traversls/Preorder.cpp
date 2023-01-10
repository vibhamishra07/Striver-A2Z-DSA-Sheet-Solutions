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


// Iterative solution: Time complexity O(n), Space O(n)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        stack<TreeNode *>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            v.push_back(node->val);
            st.pop();
            if(node->right!=NULL){
                st.push(node->right);
            }
            if(node->left!=NULL){
                st.push(node->left);
            }
        }
        return v;
    }
};


//Recursive Solution:- Time Complexity O(n), Space Complexity O(n) (function call stack)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }
    void preorder(TreeNode *root, vector<int> &v){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
};



//Morris traversal: Time Complexity O(n), Space Complexity O(1). 



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    v.push_back(root->val);
                    node->right=root;
                    root=root->left;
                }else{
                    node->right=NULL;
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


