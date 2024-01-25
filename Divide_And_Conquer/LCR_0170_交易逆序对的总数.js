function dfs(nums, temp, l, r) {
  if (l >= r) {
    return 0;
  }
  const mid = (l + r) >> 1;
  const cnt_l = dfs(nums, temp, l, mid);
  const cnt_r = dfs(nums, temp, mid + 1, r);

  // const temp = new Array(r - l + 1).fill(0);
  let cnt = cnt_l + cnt_r;

  let i = l;
  let j = mid + 1;
  let k = l;
  while (i <= mid || j <= r) {
    const left = i > mid ? Infinity : nums[i];
    const right = j > r ? Infinity : nums[j];
    if (left <= right) {
      temp[k++] = nums[i++];
    } else {
      // 计算逆序对数，left > right 说明 left 之后的数都是大于right
      // 一共有 mid - i + 1 个
      cnt += mid - i + 1;
      temp[k++] = nums[j++];
    }
  }
  for (let k = l; k <= r; k++) {
    nums[k] = temp[k];
  }

  return cnt;
}

/**
 * @param {number[]} record
 * @return {number}
 */
var reversePairs = function(record) {
  const n = record.length;
  const temp = new Array(n).fill(0);
  const ans = dfs(record, temp, 0, n - 1);
  return ans;
};

function test(nums) {
  const ans = countInversions(nums);
  console.log(ans);
  console.log(nums);
}

function main() {
  // test([6, 5, 3, 4, 1]);
  test([10, 13, 2, 9, 17, 3, 1]);
}

main();
