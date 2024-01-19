/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarraySumCircular = function (nums) {
  const n = nums.length;
  // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
  // dp[i] = max(dp[i-1]+nums[i], nums[i])
  let pre = nums[0]; // 也就是dp[i], 滚动数组的效果，优化成一个值了
  let res = nums[0];
  for (let i = 1; i < n; i++) {
      pre = Math.max(pre + nums[i], nums[i]);
      res = Math.max(res, pre);
  }

  const leftMax = new Array(n).fill(0);
  leftMax[0] = nums[0];
  let leftSum = nums[0];
  for (let i = 1; i < n; i++) {
      leftSum += nums[i];
      leftMax[i] = Math.max(leftMax[i - 1], leftSum);
  }

  // 从右到左枚举后缀，固定后缀，选择最大前缀 sum(nums[j:n])
  // 右端点坐标范围在 [0,j-1] 的最大前缀和可以用 leftMax[j-1] 表示
  let rightSum = 0;
  for (let j = n - 1; j > 0; j--) {
      rightSum += nums[j];
      res = Math.max(res, rightSum + leftMax[j - 1]);
  }
  return res;
};
