/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
  const stack = [];
  const ans = [];
  let current = root;
  while (stack.length || current) {
    while (current) {
      stack.push(current);
      current = current.left;
    }
    current = stack.pop();
    ans.push(current.val);
    current = current.right;
  }
  return ans;
};
