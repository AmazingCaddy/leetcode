/*
 * @lc app=leetcode.cn id=450 lang=javascript
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
  if (root === null) {
    return null;
  }

  if (root.val > key) {
    // 说明key在左子树
    root.left = deleteNode(root.left, key);
    return root;
  }

  if (root.val < key) {
    // 说明key在右子树
    root.right = deleteNode(root.right, key);
    return root;
  }

  if (root.val === key) {
    // 找到了要删除的节点
    if (root.left === null && root.right === null) {
      // 叶子节点，直接删除
      return null;
    }

    if (root.left !== null && root.right === null) {
      // 只有左子树
      return root.left;
    }

    if (root.left === null && root.right !== null) {
      // 只有右子树
      return root.right;
    }

    if (root.left !== null && root.right !== null) {
      let minRight = root.right;
      // 找到右子树中最小的那个节点，也就是最左的节点
      while (minRight.left) {
        minRight = minRight.left;
      }
      // 在右子树中把最小的节点删掉
      root.right = deleteNode(root.right, minRight.val);
      // 让最小的节点替代root的位置
      minRight.left = root.left;
      minRight.right = root.right;

      return minRight;
    }
  }
};
// @lc code=end

