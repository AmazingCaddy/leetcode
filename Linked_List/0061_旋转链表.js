/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
  const dummy = new ListNode(0, head);
  let fast = head;
  let n = 0;
  while (fast) {
      n++;
      fast = fast.next;
  }
  k %= n;
  fast = dummy;
  while (k > 0) {
      fast = fast.next;
      k--;
  }
  let slow = dummy;
  while (fast.next) {
      fast = fast.next;
      slow = slow.next;
  }
  fast.next = dummy.next;
  dummy.next = slow.next;
  slow.next = null;
  return dummy.next;
};