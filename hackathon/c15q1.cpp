LeetCode: 98. Validate Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isKeysInRange(root, NULL, NULL);
    }
    
    bool isKeysInRange(TreeNode* node, TreeNode* min, TreeNode* max)
    {
        if (node == NULL) return true;
        if ((min && min->val >= node->val) || (max && max->val <= node->val))
        {
            return false;
        }
        else return isKeysInRange(node->left, min, node) && isKeysInRange(node->right, node, max);;
    }
};