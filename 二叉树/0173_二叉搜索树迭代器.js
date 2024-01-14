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
 */
var BSTIterator = function (root) {
  this.cursor = root;
  this.stack = [];
};

/**
* @return {number}
*/
BSTIterator.prototype.next = function () {
  while (this.cursor) {
      this.stack.push(this.cursor);
      this.cursor = this.cursor.left;
  }
  this.cursor = this.stack.pop();
  const ret = this.cursor.val;
  this.cursor = this.cursor.right;
  return ret;
};

/**
* @return {boolean}
*/
BSTIterator.prototype.hasNext = function () {
  return this.stack.length > 0 || this.cursor !== null;
};

/**
* Your BSTIterator object will be instantiated and called as such:
* var obj = new BSTIterator(root)
* var param_1 = obj.next()
* var param_2 = obj.hasNext()
*/