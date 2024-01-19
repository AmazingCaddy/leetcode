/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
  function dfs(root) {
      if (root === null || root === p || root === q) {
          return root;
      }
      const l_has = dfs(root.left);
      const r_has = dfs(root.right);

      if (l_has === null && r_has === null) {
          return null;
      }
      if (l_has !== null && r_has !== null) {
          return root;
      }
      if (l_has === null && r_has !== null) {
          return r_has;
      }
      if (l_has !== null && r_has === null) {
          return l_has;
      }
  }

  const ans = dfs(root);
  return ans;
};