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

    /*
     each node has 3 states
     0 -> node already has a camera
     1 -> need a camera
     2 -> covered already by it's child
    */

    int camera = 0;
    int dfs(TreeNode* root, TreeNode* parent) {

        if(root == NULL) {
            return 2;
        }

        int l = dfs(root->left, root);
        int r = dfs(root->right, root);
        
        // if left or right says i need a camera
        // cur root should must cover it 
        if(l == 1 || r == 1) {
            camera++;
            return 0;
        }
            
        if(l==0 || r == 0) {
            return 2;
        }

        if(parent == NULL) {
            camera++;
        }
        return 1;
        
    }

    int minCameraCover(TreeNode* root) {
        dfs(root, NULL);
        return camera;    
    }
};