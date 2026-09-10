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
private:
    int matchingNodesCount = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int totalSum = root->val + leftSum + rightSum;
        int totalCount = 1 + leftCount + rightCount;

        if (totalSum / totalCount == root->val) {
            matchingNodesCount++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        dfs(root);
        return matchingNodesCount;
    }
};