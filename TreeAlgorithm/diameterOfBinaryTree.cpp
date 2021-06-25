class Solution {
public:
    int maxL = INT_MIN;
    
    int diameterOfBinaryTree2(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l = diameterOfBinaryTree2(root->left);
        int r = diameterOfBinaryTree2(root->right);
        if(l+r>maxL)
            maxL = l+r;
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode * root){
        maxL = INT_MIN;
        int t = diameterOfBinaryTree2(root);
        return maxL;
    }
};
