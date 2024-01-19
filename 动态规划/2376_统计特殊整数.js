/**
 * @param {number} n
 * @return {number}
 */
var countSpecialNumbers = function (n) {
  const s = `${n}`;
  const cache = Object.create(null);

  /**
   * 假设 s 是 n 的字符串表示形式，从第 i 位开始填数字，i 前面填的数字集合是 mask，能构造出的特殊整数的数目
   * @param {*} i 第 i 位
   * @param {*} mask 前面 i-1 位已经填的数字集合
   * @param {*} is_limit 表示前面 i-1 位 填的数字是否都是 n 对应位上的数字 如果为true 那么当前位至多为 int(s[i])，否则至多为 9
   * @param {*} is_num 表示前面 i-1 位 是否填了数字 如果为true 那么当前可以从 0 开始 否则 我们可以跳过，或者从 1 开始
   */
  function dfs(i, mask, is_limit, is_num) {
    if (i === s.length) {
      // true 表示前面填了数字，那么就找到一个合法的数字，否则没有找到
      return is_num ? 1 : 0;
    }

    const cache_key = [i, mask, is_limit, is_num].join("|");
    if (!cache[cache_key]) {
      let res = 0;
      if (is_num === false) {
        // 前面没有填数字，这里继续选择跳过，前面有跳过的，那么也不会有限制
        res = dfs(i + 1, mask, false, false);
      }
      // 计算一下上界
      const up = is_limit ? parseInt(s[i]) : 9;
      // is_num = false 下界为 1
      for (let d = is_num ? 0 : 1; d <= up; d++) {
        if (((mask >> d) & 1) === 0) {
          // 说明 mask 里面没有 d
          res += dfs(i + 1, mask | (1 << d), is_limit && d === up, true);
        }
      }
      cache[cache_key] = res;
    }

    return cache[cache_key];
  }

  // 第 0 位 不能超过 s[i] 所以 is_limit 需要初始化成 true
  return dfs(0, 0, true, false);
};
