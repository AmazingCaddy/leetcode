/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
  const dummy = new Node(-1, null);

  const node2IndexMap = new Map();
  const copiedNodeList = [];

  let p = head;
  let index = 0;
  while (p) {
      node2IndexMap.set(p, index);
      p = p.next;
      index++;
  }

  let q = dummy;
  p = head;
  while (p) {
      const node = new Node(p.val, null);
      copiedNodeList.push(node);
      q.next = node;
      q = q.next;
      p = p.next;
  }

  q = dummy.next;
  p = head;
  while (p) {
      q.random = copiedNodeList[node2IndexMap.get(p.random)];
      p = p.next;
      q = q.next;
  }
  return dummy.next;
};