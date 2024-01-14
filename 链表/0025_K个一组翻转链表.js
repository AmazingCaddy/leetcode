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
var reverseKGroup = function (head, k) {
  const dummy = new ListNode(0, head);
  let start = dummy;
  let end = dummy;
  while (end.next) {
      for (let i = 0; i < k && end !== null; i++) {
          end = end.next;
      }
      if (end === null) {
          break;
      }

      const head = start.next;
      // 下一段待逆转链表的头节点
      const next_head = end.next;

      end.next = null;
      start.next = reverseList(head);
      // 逆转完之后，head逆转链表的最后一个，也是下一个待逆转链表的前一个
      head.next = next_head;
      // start 和 end 都指向下一段链表头节点的前一个节点
      start = head;
      end = start;
  }
  return dummy.next;
};

function reverseList(head) {
  let prev = null;
  let curr = head;
  while (curr) {
      const next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
  }
  return prev;
};