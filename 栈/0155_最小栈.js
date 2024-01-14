
var MinStack = function () {
  this.stack = [];
  this.minStack = [];
  this.min = -Infinity;
};

/** 
* @param {number} val
* @return {void}
*/
MinStack.prototype.push = function (val) {
  this.stack.push(val);
  if (this.stack.length === 1) {
      this.minStack.push(val);
  } else {
      const min = Math.min(this.minStack[this.minStack.length - 1], val);
      this.minStack.push(min);
  }
};

/**
* @return {void}
*/
MinStack.prototype.pop = function () {
  this.stack.pop();
  this.minStack.pop();
};

/**
* @return {number}
*/
MinStack.prototype.top = function () {
  const value = this.stack[this.stack.length - 1];
  return value;
};

/**
* @return {number}
*/
MinStack.prototype.getMin = function () {
  const value = this.minStack[this.minStack.length - 1];
  return value;
};

/**
* Your MinStack object will be instantiated and called as such:
* var obj = new MinStack()
* obj.push(val)
* obj.pop()
* var param_3 = obj.top()
* var param_4 = obj.getMin()
*/