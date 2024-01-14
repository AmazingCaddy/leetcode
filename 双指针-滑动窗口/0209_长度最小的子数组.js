/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function (target, nums) {
  const n = nums.length;
  let l = 0;
  let r = 0;
  let sum = 0;
  let ans = Infinity;
  while (r < n) {
      sum += nums[r];
      while (sum >= target) {
          const temp = (r - l + 1);
          if (temp < ans) {
              ans = temp;
          }
          sum -= nums[l];
          l++;
      }
      r++;
  }
  return ans === Infinity ? 0 : ans;
};