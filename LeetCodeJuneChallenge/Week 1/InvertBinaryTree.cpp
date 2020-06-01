// Day 1
/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
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
    //O(n) time | O(n) space
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        //recursive approach
        TreeNode* left  = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->right = left;
        root->left = right;
        //iterative approach
        /*queue<TreeNode*> q;
        q.push(root);
            while(!q.empty()){
                TreeNode* current = q.front();
                q.pop();

                TreeNode* temp = current->left;
                current->left = current->right;
                current->right = temp;

                if(current->left != NULL){
                    q.push(current->left);
                }
                if(current->right != NULL){
                    q.push(current->right);
                }
            }*/
        return root;
    }
};
