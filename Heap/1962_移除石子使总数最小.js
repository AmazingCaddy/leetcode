/**
 * @param {number[]} piles
 * @param {number} k
 * @return {number}
 */
var minStoneSum = function (piles, k) {
  const queue = new Array(k + 1).fill(null);
  piles.sort((a, b) => a - b);
  let ans = 0;
  for (let i = 0; i < piles.length; i++) {
    ans += piles[i];
  }
  let tail = piles.length - 1;
  let qHead = 0;
  let qTail = 0;
  while (k > 0) {
    let current = 0;
    if (qTail - qHead === 0 || (tail >= 0 && piles[tail] > queue[qHead])) {
      current = piles[tail];
      tail--;
    } else {
      current = queue[qHead];
      qHead++;
    }
    const rest = current - (current >> 1);
    ans -= current >> 1;
    queue[qTail] = rest;
    qTail++;
    k--;
  }
  return ans;
};
