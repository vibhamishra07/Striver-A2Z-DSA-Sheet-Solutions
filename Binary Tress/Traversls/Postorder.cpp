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

// Iterative Solution : O(n) time O(n) sapce

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode *> st;
        while (root != NULL || !st.empty()) {
            if (root != NULL) {
                st.push(root);
                root = root -> left;
            } else {
                TreeNode * temp = st.top() -> right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    v.push_back(temp -> val);
                    while (!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        v.push_back(temp -> val);
                    }
                } else root = temp;
            }
        }
        return v;
    }
};

// OR 


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
           auto p=st.top();
           if(p==nullptr){
               st.pop();
               v.push_back(st.top()->val);
               st.pop();
               continue;
           }
           st.push(nullptr);
           if(p->right) st.push(p->right);
           if(p->left) st.push(p->left);
            
        }
        return v;
    }
};


//Recursive Solution:- Time Complexity O(n), Space Complexity O(n) (function call stack)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root, v);
        return v;
    }
    void postorder(TreeNode *root,vector<int>& v){
        if(root==NULL) return ;
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }
};






