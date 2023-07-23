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
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return {};
    if (n == 1)
      return {new TreeNode(0)};
    if (const auto it = memo.find(n); it != memo.cend())
      return it->second;

    vector<TreeNode*> ans;

    for (int leftCount = 0; leftCount < n; ++leftCount) {
      const int rightCount = n - 1 - leftCount;
      for (TreeNode* left : allPossibleFBT(leftCount))
        for (TreeNode* right : allPossibleFBT(rightCount)) {
          ans.push_back(new TreeNode(0));
          ans.back()->left = left;
          ans.back()->right = right;
        }
    }

    return memo[n] = ans;
  }

 private:
  unordered_map<int, vector<TreeNode*>> memo;
};
