/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function (head, x) {
  const dummy = new ListNode(0, head);
  const dummy_large = new ListNode(0, null);

  let cur = dummy;
  let cur_large = dummy_large;
  while (cur.next) {
      if (cur.next.val >= x) {
          // 临时存储to_del节点 需要接到 cur_large 后面
          const to_del = cur.next;
          // 删除 to_del 节点
          cur.next = to_del.next;
          // to_del 作为 cur_large 的最后一个节点
          to_del.next = null;
          cur_large.next = to_del;
          cur_large = cur_large.next;
      } else {
          cur = cur.next;
      }
  }
  cur.next = dummy_large.next;
  return dummy.next;
};