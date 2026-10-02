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
    int postOrder(TreeNode* &root) {
        if(root == NULL) return 0;
  
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        
        if(left == 0) root->left = NULL;
        if(right == 0) root->right = NULL;
        int one = 0;
        if(root->val == 1) one=1;
        if(root->val == 0 && left == 0 && right == 0) {
          
            root = NULL;


        } 

   
        return one +left+right;

    }
   
    TreeNode* pruneTree(TreeNode* root) {
           postOrder(root);
           return root; 
    }
};