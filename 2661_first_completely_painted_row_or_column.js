/**
 * @param {number[]} arr
 * @param {number[][]} mat
 * @return {number}
 */
var firstCompleteIndex = function (arr, mat) {
  const m = mat.length;
  const n = mat[0].length;
  const rowChecker = new Array(m).fill(0);
  const colChecker = new Array(n).fill(0);
  const total = arr.length;
  const rcMap = new Array(total + 1).fill(0);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      rcMap[mat[i][j]] = [i, j];
    }
  }
  for (let i = 0; i < total; i++) {
    const [row, col] = rcMap[arr[i]];
    rowChecker[row]++;
    colChecker[col]++;
    if (rowChecker[row] === n || colChecker[col] === m) {
      return i;
    }
  }
  return total - 1;
};
