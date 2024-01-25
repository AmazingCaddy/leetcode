/*
 * @lc app=leetcode.cn id=133 lang=javascript
 *
 * [133] 克隆图
 */

// @lc code=start

// Definition for a Node.
function Node(val, neighbors) {
  this.val = val === undefined ? 0 : val;
  this.neighbors = neighbors === undefined ? [] : neighbors;
}

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function (node) {
  const ans = bfs(node);
  // const ans = [];
  // for (const key of [...nodeMap.keys()].sort()) {
  //   ans.push(nodeMap.get(key).neighbors);
  // }
  return ans;
};

function bfs(start) {
  const nodeMap = new Map();
  if (start === null) {
    return null;
  }
  const queue = [start];
  nodeMap.set(start.val, new Node(start.val, []));
  while (queue.length) {
    const u = queue.shift();
    const clone = nodeMap.get(u.val);
    for (const v of u.neighbors) {
      if (!nodeMap.get(v.val)) {
        nodeMap.set(v.val, new Node(v.val, []));
        queue.push(v);
      }
      clone.neighbors.push(nodeMap.get(v.val));
    }
  }
  return nodeMap.get(start.val);
}

// @lc code=end

function main() {
  const nodes = new Array(4).fill(0).map((_, index) => new Node(index+1, []));
  nodes[0].neighbors.push(nodes[1], nodes[3]);
  nodes[1].neighbors.push(nodes[0], nodes[2]);
  nodes[2].neighbors.push(nodes[1], nodes[3]);
  nodes[3].neighbors.push(nodes[0], nodes[2]);
  cloneGraph(nodes[0]);
}

main();