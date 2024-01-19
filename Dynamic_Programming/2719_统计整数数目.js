const MOD = 1e9 + 7;

/**
 * @param {string} num1
 * @param {string} num2
 * @param {number} min_sum
 * @param {number} max_sum
 * @return {number}
 */
var count = function (num1, num2, min_sum, max_sum) {
  const a = _count(num1, min_sum, max_sum);
  const b = _count(num2, min_sum, max_sum);
  const temp = b - a + is_good_number(num1, min_sum, max_sum) + MOD;
  return temp % MOD;
};

function is_good_number(num, min_sum, max_sum) {
  let sum = 0;
  for (const c of num) {
    sum += parseInt(c);
  }
  return sum >= min_sum && sum <= max_sum;
}

function _count(s, min_sum, max_sum) {
  const n = s.length;
  const cache = Object.create(null);

  function dfs(i, sum, is_limit) {
    // 剪枝：如果加起来已经大于max_sum，直接返回0
    if (sum > max_sum) {
      return 0;
    }
    if (i === n) {
      return sum >= min_sum ? 1 : 0;
    }
    const cache_key = [i, sum, is_limit].join("|");
    if (cache[cache_key] === undefined) {
      let res = 0;
      const up = is_limit ? parseInt(s[i]) : 9;
      for (let d = 0; d <= up; d++) {
        res = (res + dfs(i + 1, sum + d, is_limit && d === up)) % MOD;
      }
      cache[cache_key] = res;
    }
    return cache[cache_key];
  }

  return dfs(0, 0, true);
}

function main() {
  const num1 = "1012640017461217236611";
  const num2 = "9234552128261772272769";
  const min_sum = 67;
  const max_sum = 148;
  const ans = count(num1, num2, min_sum, max_sum);
  console.log(ans);
}

main();
