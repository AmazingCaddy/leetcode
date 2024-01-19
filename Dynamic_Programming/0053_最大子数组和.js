/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
  const n = nums.length;
  const dp = new Array(n + 1).fill(-Infinity);

  let ans = nums[0];
  dp[0] = nums[0];
  for (let i = 1; i < n; i++) {
      dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
      ans = Math.max(ans, dp[i]);
  }

  return ans;
};