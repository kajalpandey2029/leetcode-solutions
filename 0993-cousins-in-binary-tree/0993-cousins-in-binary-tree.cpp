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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {  
            bool fX = false;
            bool fY = false;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && node->right) {
                    if((node->left->val == x && node->right->val == y) ||
                       (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if(node->val == x) {
                    fX = true;
                }
                if(node->val == y) {
                    fY = true;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            // dono same level pe nhi h
            if(fX && fY) {
                return true;
            }
            // koi eak us level pe hai
            if(fX || fY) {
                return false;
            }
        }
        return false;
    }
};