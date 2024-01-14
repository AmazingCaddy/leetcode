/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens) {
  const ops = {
      "+": (a, b) => a + b,
      "-": (a, b) => a - b,
      "*": (a, b) => a * b,
      "/": (a, b) => a / b > 0 ? Math.floor(a / b) : Math.ceil(a / b),
  };
  const n = tokens.length;
  const stack = [];
  let ans = 0;
  for (let i = 0; i < n; i++) {
      const t = tokens[i];
      if (ops[t]) {
          const op1 = stack.pop();
          const op2 = stack.pop();
          ans = ops[t](op2, op1);
          stack.push(ans);
      } else {
          stack.push(parseInt(t));
      }
  }
  return stack.pop();
};