/*
 * @lc app=leetcode.cn id=3 lang=javascript
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const cntMap = Object.create(null);
  const n = s.length;
  let ans = 0;
  let l = 0;
  for (let r = 0; r < n; r ++) {
    const rc = s[r];
    if (cntMap[rc] === undefined) {
      cntMap[rc] = 0;
    }
    cntMap[rc]++;
    if (cntMap[rc] > 1) {
      while (l <= r && cntMap[rc] > 1) {
        const lc = s[l];
        cntMap[lc] --;
        l ++;
      }
    }
    const len = r - l + 1;
    if (len > ans) {
      ans = len;
    }
  }
  return ans;
};
// @lc code=end

