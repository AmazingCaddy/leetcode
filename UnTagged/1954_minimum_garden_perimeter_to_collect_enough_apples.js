/**
 * @param {number} neededApples
 * @return {number}
 */
var minimumPerimeter = function (neededApples) {
  // 推导出公式为 2n(n+1)(2n+1)
  let l = 1;
  let r = 100000;
  while (l <= r) {
    const mid = (l + r) >> 1;
    const ans = 2 * mid * (mid + 1) * (2 * mid + 1);
    if (ans < neededApples) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l * 8;
};
