/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  const n = nums.length;
  let cnt = 0;
  for (let i = 0; i < n; i++) {
      if (nums[i] !== val) {
          nums[cnt] = nums[i];
          cnt ++;
      }
  }
  return cnt;
};