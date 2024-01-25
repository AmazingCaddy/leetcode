/*
 * @lc app=leetcode.cn id=215 lang=javascript
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function (nums, k) {
  const n = nums.length;
  k = n - k;
  // console.log(`k = ${k}`);
  const ans = dfs(nums, 0, n - 1, k);
  return ans;
};

function dfs(nums, l, r, k) {
  if (l === r) {
    return nums[k];
  }
  const pivot = hoare_partition(nums, l, r);
  if (k <= pivot) {
    return dfs(nums, l, pivot, k);
  }
  return dfs(nums, pivot + 1, r, k);
}

function hoare_partition(arr, low, high) {
  const pivot = arr[low];
  let i = low - 1;
  let j = high + 1;
  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j) {
      return j;
    }
    // Swap arr[i] and arr[j]
    [arr[i], arr[j]] = [arr[j], arr[i]];
  }
}

// @lc code=end

function test(nums, k) {
  const ans = findKthLargest(nums, k);
  console.log(ans);
}

// function main() {
//   test([3, 2, 3, 1, 2, 4, 5, 5, 6], 4);
//   test([99, 99], 1);
//   test([3, 2, 1, 5, 6, 4], 2);
//   test([7, 6, 5, 4, 3, 2, 1], 2);
// }

// main();
