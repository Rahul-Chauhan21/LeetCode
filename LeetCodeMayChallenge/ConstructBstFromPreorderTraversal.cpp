//Day 24
/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Constraints:

    1 <= preorder.length <= 100
    1 <= preorder[i] <= 10^8
    The values of preorder are distinct.


*/
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
private:
    TreeNode* helper(const vector<int>& preorder,int& id, int limit){
        if(id == (int)preorder.size() || preorder[id] > limit){
            return NULL;
        }
        int root_value = preorder[id];
        TreeNode* root = new TreeNode(root_value);
        id++;
        root->left = helper(preorder,id,root_value);
        root->right = helper(preorder,id,limit);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //using limit to recursively check the position.
        /*int id = 0;
        return helper(preorder,id,INT_MAX);
        */
        //using stack
        if(preorder.empty())
            return NULL;
        int root_value = preorder[0];
        TreeNode* root = new TreeNode(root_value);
        stack<TreeNode*> st;
        st.push(root);

            for(int i = 1; i < preorder.size(); ++i){
                if(st.top()->val > preorder[i]){
                    st.top()->left = new TreeNode(preorder[i]);
                    st.push(st.top()->left);
                }
                else{
                    TreeNode* child = NULL;
                    while(!st.empty() && st.top()->val < preorder[i]){
                        child = st.top();
                        st.pop();
                    }

                    child->right = new TreeNode(preorder[i]);
                    st.push(child->right);
                }

            }
        return root;
        /*O(n2) for every level the sequence is traversed again. for a sequence to be traversed n times it              has to be sorted such sequence would give an unbalanced bst or skew tree.*/
        /*if(preorder.empty()){
            return NULL;
        }
        int root_value = preorder[0];
        vector<int> smaller,greater;
        for(int i = 1; i < (int) preorder.size(); i++){
            if(preorder[i] > root_value){
                greater.push_back(preorder[i]);
            }
            else{
                smaller.push_back(preorder[i]);
            }
        }
        TreeNode* root = new TreeNode(root_value);
        root->left = bstFromPreorder(smaller);
        root->right = bstFromPreorder(greater);
        return root;*/
    }
};
