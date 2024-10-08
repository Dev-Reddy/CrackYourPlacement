class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
        {
            return 0;
        }

        int ans = 0;

        if (root->val < low)
        {
            ans = rangeSumBST(root->right, low, high);
        }
        else if (root->val > high)
        {
            ans = rangeSumBST(root->left, low, high);
        }
        else if (root->val >= low && root->val <= high)
        {
            int left = rangeSumBST(root->left, low, high);
            int right = rangeSumBST(root->right, low, high);
            ans = root->val + left + right;
        }

        return ans;
    }
};