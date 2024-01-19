/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
  const n  = nums.length;
  const d = [];
  for (const num of nums) {
    const index = upper_bound(d, nums[i]);
    if (index === d.length) {
      d.push(nums[i]);
    } else {
      d[index] = Math.min(d[index], nums[i]);
    }
  }
  return d.length;
};

// 第一个 > target 的数字下标
function upper_bound(nums, target) {
  let l = 0;
  let r = nums.length;
  while (l < r) {
    const mid = (l + r) >> 1;
    if (num[mid] <= target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
