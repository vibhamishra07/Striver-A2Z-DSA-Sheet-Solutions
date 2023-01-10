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
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;

        if(isBal(root)==-1){
            return false;
        }
        return true;

    }
    int isBal(TreeNode* root) {
        if(root==NULL)return 0;
        int leftDepth=isBal(root->left);
        int rightDepth=isBal(root->right);
        
        if(leftDepth==-1 || rightDepth==-1 || abs(leftDepth-rightDepth)>1) return -1;
        return 1+max(leftDepth, rightDepth);
        
    }
};