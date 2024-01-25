/*
 * @lc app=leetcode.cn id=69 lang=javascript
 *
 * [69] x 的平方根 
 */

// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
  const ans = bin_search(x);
  return ans - 1;
};

function bin_search(x) {
  let l = 0;
  let r = (1 << 16) - 1;
  while (l < r) {
    const mid = (l + r) >> 1;
    if (mid * mid <= x) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

// @lc code=end

function test(x) {
  const ans = mySqrt(x);
  console.log(`sqrt(${x}) = ${ans}`);
}

function main()  {
  for (let i = 1; i < 128; i ++) {
    test(i);
  }
}

main();
