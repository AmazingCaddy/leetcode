/*
 * @lc app=leetcode.cn id=25 lang=javascript
 *
 * [25] K 个一组翻转链表
 */

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *  this.val = val === undefined ? 0 : val;
 *  this.next = next === undefined ? null : next;
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
    for (let i = 0; i < k && end !== null; i ++) {
      end = end.next;
    }
    if (end === null) {
      // 说明是最后不满足k个节点的部分
      break;
    }
    
    // 保存当前分组的头节点
    let head = start.next;
    // 保存下一个分组的头节点
    let next_head = end.next;

    // 截断当前分组
    end.next = null;
    // 进行反转
    const reverse_head = reverse(head);

    // 当前分组的前置节点链接到反转之后的头节点
    start.next = reverse_head;
    // 反转之后，头节点成为了尾节点，所以head的next节点为下个分组的头节点
    head.next = next_head;

    // start 和 end 移动到下一个分组的前置节点
    start = head;
    end = head;
  }

  return dummy.next;
};

function reverse(head) {
  let prev = null;
  let cur = head;
  while (cur) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

// @lc code=end

function print_list(head) {
  let cur = head;
  while (cur) {
    console.log(cur.val);
    cur = cur.next;
  }
}

function test(values) {
  const nodes = [];
  for (let i = 0; i < values.length; i++) {
    const node = new ListNode(values[i]);
    nodes.push(node);
    if (i > 0) {
      nodes[i - 1].next = node;
    }
  }
  const head = reverseKGroup(nodes[0], 2);
  print_list(head);
}

function main() {
  const values = [1, 2, 3, 4, 5];
  test(values);
}

main();
