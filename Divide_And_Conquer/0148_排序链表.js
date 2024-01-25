/*
 * @lc app=leetcode.cn id=148 lang=javascript
 *
 * [148] 排序链表
 */

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function (head) {
  let len = 0;
  let cur = head;
  while (cur) {
    cur = cur.next;
    len++;
  }
  return merge_sort(head, len);
};

function merge_sort(head, len) {
  if (len <= 1) {
    return head;
  }

  const llen = len >> 1;
  const rlen = len - llen;

  const dummy = new ListNode(0, head);

  let pre = dummy;
  for (let i = 0; i < llen; i++) {
    pre = pre.next;
  }

  const head_l = dummy.next;
  const head_r = pre.next;
  pre.next = null;

  let h1 = merge_sort(head_l, llen);
  let h2 = merge_sort(head_r, rlen);

  let h3 = dummy;
  while (h1 && h2) {
    const l_v = h1.val;
    const r_v = h2.val;
    if (l_v <= r_v) {
      h3.next = h1;
      h1 = h1.next;
    } else {
      h3.next = h2;
      h2 = h2.next;
    }
    h3 = h3.next;
  }
  if (h1) {
      h3.next = h1;
  }
  if (h2) {
      h3.next = h2;
  }

  // console.log(h3.next);
  return dummy.next;
}

// @lc code=end

// @after-stub-for-debug-begin
module.exports = sortList;
// @after-stub-for-debug-end