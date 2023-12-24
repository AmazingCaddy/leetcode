/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function (cardPoints, k) {
  const n = cardPoints.length;
  cardPoints = cardPoints.concat(cardPoints.slice(0, k));
  let start = n - k;
  let ans = 0;
  for (let i = start; i < n; i++) {
    ans += cardPoints[i];
  }
  const end = n + k;
  let temp = ans;
  for (let i = n; i < end; i++) {
    temp = temp - cardPoints[i - k] + cardPoints[i];
    if (temp > ans) {
      ans = temp;
    }
  }
  return ans;
};
