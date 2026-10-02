/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class Solution {

    int postOrder(TreeNode root) {
        if(root == null) return 0;

        int left = postOrder(root.left);
        int right = postOrder(root.right);
        
        if(left == 0) root.left = null;
        if(right == 0) root.right = null;
        int one = 0;
        if(root.val == 1) one=1;
        if(root.val == 0 && left == 0 && right == 0) {
            // System.out.println("ENTERED here" + root.val);
            root = null;
        } 
        return one +left+right;

    }
    public TreeNode pruneTree(TreeNode root) {
        int r = postOrder(root);
        if(r == 0) return null;
        return root;    
    }
}