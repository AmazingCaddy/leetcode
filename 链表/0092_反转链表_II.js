/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function (head, left, right) {
  const dummy = new ListNode(0, head);

  let tail = dummy;
  for (let i = 1; i < left; i++) {
      tail = tail.next;
  }

  // 记录逆转链表的头节点的上一个节点
  const pre_head = tail;
  // 记录逆转链表的头节点
  const original_head = tail.next;

  // 逆转链表，逆转完之后prev为头节点，curr为剩余链表的头节点
  let prev = null;
  let curr = original_head;
  for (let i = left; i <= right; i++) {
      const next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
  }

  // 逆转链表之前的前一个的下一个节点等于逆转链表的头节点
  pre_head.next = prev;
  // 逆转链表的头节点就是逆转之后的尾节点，尾节点的下一个节点为剩余链表的头节点
  original_head.next = curr;

  return dummy.next;
};