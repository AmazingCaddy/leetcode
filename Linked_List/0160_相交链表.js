/*
 * @lc app=leetcode.cn id=160 lang=javascript
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
  // 让两个链表走过的距离相等，最终会在交叉点相遇
  // 距离相等的方式是，A走完了之后去B，B走完了去A，交叉一下。
  let h1 = headA;
  let h2 = headB;
  while (h1 !== h2) {
      h1 = h1 === null ? headB : h1.next;
      h2 = h2 === null ? headA : h2.next;
  }
  return h1;
};
// @lc code=end

