//  binary tree's maximum depth is the number of nodes along the longest path from 
//  the root node down to the farthest leaf node.



class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);

        return 1+max(leftDepth, rightDepth);
        
    }
}

// time: O(n), space: O(1)+O(h) h=height of a tree.