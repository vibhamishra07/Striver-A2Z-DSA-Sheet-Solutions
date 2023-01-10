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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            vector<int> lev;
            for(int i=0; i<n; i++){
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                lev.push_back(que.front()->val);
                que.pop();
            }
            v.push_back(lev);
        }
        return v;
    }
};