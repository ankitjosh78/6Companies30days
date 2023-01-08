#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> ans;
  void traverse(TreeNode *root) {
    if (!root)
      return;
    ans.push_back(root->val);
    traverse(root->left);
    traverse(root->right);
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    /*
    Approach:
    Traversing both the trees and putting all the nodes in a list.
    Sorting the list and returing!
    */
    traverse(root1);
    traverse(root2);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
