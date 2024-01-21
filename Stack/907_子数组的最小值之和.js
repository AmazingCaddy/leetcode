/**
 * left 数组
 * left[i]  表示 arr[i] 左边第一个  < arr[i] 的数字下标
 * @param {*} arr
 * @returns {Array<Number>}
 */
function calLeft(arr) {
  const n = arr.length;
  // 初始换左边界都为-1
  const left = new Array(n).fill(-1);
  const st = [];
  for (let i = 0; i < n; i++) {
    while (st.length && arr[st[st.length - 1]] >= arr[i]) {
      // 移除栈顶元素，直到栈顶元素小于当前元素或者栈为空
      st.pop();
    }
    if (st.length) {
      // 栈顶元素为左边界
      left[i] = st[st.length - 1];
    }
    st.push(i);
  }
  return left;
}

/**
 * right 数组
 * right[i] 表示 arr[i] 右边第一个 <= arr[i] 的数字下标
 * @param {*} arr
 * @returns {Array<Number>}
 */
function calRight(arr) {
  const n = arr.length;
  // 初始化右边界都为n
  const right = new Array(n).fill(n);
  const st = [];
  for (let i = n - 1; i >= 0; i--) {
    while (st.length && arr[st[st.length - 1]] > arr[i]) {
      // 移除栈顶元素，直到栈顶元素小于当前元素或者栈为空
      st.pop();
    }
    if (st.length) {
      // 栈顶元素为右边界
      right[i] = st[st.length - 1];
    }
    st.push(i);
  }
  return right;
}

/**
 * 为了防止重复计算， right 需要被定义成 arr[i] 右边第一个 <= arr[i] 的下标
 * 一般地，设 arr[i] 对应的边界为开区间 (left[i], right[i])
 * 由于子数组必须包含 arr[i]:
 *    子数组的左端点可以是 left[i]+1, left[i]+2, ... , i，共有 i-left[i] 个
 *    子数组的右端点可以是 i, i+1, ... , right[i]-1 共有 right[i]−i 个
 * arr[i] 对答案的贡献是 arr[i] * (i-left[i]) * (right[i]-i)
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function (arr) {
  const left = calLeft(arr);
  const right = calRight(arr);
  // console.log(left);
  // console.log(right);
  const n = arr.length;
  const MOD = 1e9 + 7;
  let ans = 0;
  for (let i = 0; i < n; i++) {
    ans = (ans + arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
  }
  return ans;
};

function test() {
  const arr = [3, 1, 2, 4];
  const ans = sumSubarrayMins(arr);
  console.log(ans);
}

test();
