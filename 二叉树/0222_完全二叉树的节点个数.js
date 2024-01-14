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
 * @return {number}
 */
var countNodes = function (root) {
  if (root === null) {
      return 0;
  }
  let level = 0;
  let cur = root;
  while (cur.left) {
      level++;
      cur = cur.left;
  }

  // 找到第一个不存在的节点 x，答案就是 x-1
  // [low, high)
  let low = 1 << level;
  let high = low << 1;
  while (low < high) {
      const mid = (low + high) >> 1;
      if (exists(root, level, mid)) {
          low = mid + 1;
      } else {
          high = mid;
      }
  }
  return low - 1;
};

function exists(root, level, k) {
  let mask = 1 << (level - 1);
  let cur = root;
  while (cur && mask > 0) {
      if ((mask & k) === 0) {
          cur = cur.left;
      } else {
          cur = cur.right;
      }
      mask >>= 1;
  }
  return cur !== null;
}

function main() {
  const tree = [1, 2, 3, 4, 5, 6];
  const treeNodes = new Array(6).fill(null);
  for (let i = 0; i < treeNodes.length; i++) {
      treeNodes[i] = new TreeNode(tree[i], null, null);
  }
  const root = treeNodes[0];
  root.left = treeNodes[1];
  root.right = treeNodes[2];
  treeNodes[1].left = treeNodes[3];
  treeNodes[1].right = treeNodes[4];
  treeNodes[2].left = treeNodes[5];
  const ans = countNodes(root);

  console.log(ans);
}

main();
