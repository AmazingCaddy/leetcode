/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  for (const c of s) {
      if (c === '(') {
          stack.push(')');
      } else if (c === '[') {
          stack.push(']');
      } else if (c === '{') {
          stack.push('}');
      } else {
          if (stack.length === 0) {
              return false;
          }
          if (stack[stack.length - 1] !== c) {
              return false;
          }
          stack.pop();
      }
  }

  return stack.length === 0;
};