//Day 7
/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
*/

/*
                                        1
                                      /   \
                                     2     3
                                    /
                                   4
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false
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
        int find_HeightParent(TreeNode* current,int &parent, int value, int depth){
            if(current == NULL){
                return 0;
            }

            if(current->val == value){
                return depth;
            }

            parent = current->val;
            int check_left = find_HeightParent(current->left,parent,value,depth+1);
            if(check_left){
                return check_left; //value found in the left subtree and it returns the depth
            }
            parent = current->val;
            int right_check = find_HeightParent(current->right,parent,value,depth+1);
            return right_check;
        }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root-> val == x || root->val == y){
            return false;
        }

        int xParent = -1;
        int xHeight = find_HeightParent(root,xParent,x,0);

        int yParent = -1;
        int yHeight = find_HeightParent(root,yParent,y,0);

            if(xParent != yParent && xHeight == yHeight){
                return true;
            }
        return false;
    }
};
