/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function (path) {
  const steps = path.split('/');
  const stack = [];
  const n = steps.length;
  for (let i = 0; i < n; i++) {
      const step = steps[i];
      if (step === '.') {
          continue;
      } else if (step === '..') {
          stack.pop();
      } else if (step === '') {
          continue;
      } else {
          stack.push(step);
      }
  }
  return '/' + stack.join('/')
};