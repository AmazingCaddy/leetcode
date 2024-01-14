function convert2Set(list) {
  const set = list.split("|").reduce((dict, cur) => {
    dict[cur] = true;
    return dict;
  }, {});
  return set;
}

const numberList = "0|1|2|3|4|5|6|7|8|9";
const opList = "+|-|*|/|^|u+|u-";
const opRightList = "^";
const parentheses = "(|)";

const numberSet = convert2Set(numberList);
const opSet = convert2Set(opList);
const opRightSet = convert2Set(opRightList);
const parenthesesSet = convert2Set(parentheses);

const opPriority = {
  "u+": 4,
  "u-": 4,
  "^": 3,
  "*": 2,
  "/": 2,
  "%": 2,
  "+": 1,
  "-": 1,
};

const opFunMap = {
  "u+": (a) => a,
  "u-": (a) => -a,
  "*": (a, b) => a * b,
  "/": (a, b) => Math.floor(a / b),
  "%": (a, b) => a % b,
  "+": (a, b) => a + b,
  "-": (a, b) => a - b,
};

function parse(str) {
  const n = str.length;
  const tokens = [];
  let current = "";
  for (let i = 0; i < n; i++) {
    const c = str[i];
    if (numberSet[c]) {
      current += c;
    } else {
      if (current !== "") {
        tokens.push({ value: current, type: "number" });
        current = "";
      }
      if (opSet[c]) {
        tokens.push({ value: c, type: "operation" });
      } else if (parenthesesSet[c]) {
        tokens.push({ value: c, type: "parentheses" });
      }
    }
  }
  if (current !== "") {
    tokens.push({ value: current, type: "number" });
    current = "";
  }
  return tokens;
}

function middle2Suffix(tokens) {
  let lastToken = null;
  const n = tokens.length;
  for (let i = 0; i < n; i++) {
    const token = tokens[i];
    if (token.value === "+" || token.value === "-") {
      if (
        // 运算符的开始
        lastToken === null ||
        // 前一个不是操作数也不是右括号
        (lastToken.type !== "number" && lastToken.value !== ")")
      ) {
        // 处理一元运算符
        token.value = "u" + token.value;
      }
    } else if (token.type === "number") {
      token.value = parseInt(token.value);
    }
    lastToken = token;
  }

  // console.log(tokens);

  /**
   * 遍历中缀表达式：
   * 1 如果是 操作数，读取其所有的位，然后进入后缀表达式队列；
   * 2 如果是 操作符 ( + – * / ^ % )
   *    2.1 如果 "操作符栈" 为空，直接入栈；
   *    2.2 如果 当前操作符优先级 > 栈顶元素优先级 那么入栈；
   *    2.3 如果 当前操作符优先级 < 栈顶元素优先级 那么栈顶操作符出栈，循环执行；
   *    2.4 如果 当前操作符优先级 = 栈顶元素优先级
   *        2.4.1 如果当前元素是右结合性，那么入栈
   *        2.4.2 否则，栈顶元素出栈；循环执行。
   * 3 如果是 左括号'('，直接入栈
   * 4 如果是 右括号')'，如果栈非空，那么栈顶元素出栈，直到遇到左括号'('；
   * 5 遍历结束中，将操作符栈中的元素依次出栈，添加到后缀表达式队列中。
   */

  // 后缀表达式序列
  const queue = [];
  // 操作符栈
  const opStack = [];

  for (let i = 0; i < n; i++) {
    const token = tokens[i];
    const { type, value } = token;
    if (type === "number") {
      // 操作数
      queue.push(token);
    } else if (type === "parentheses") {
      // 括号
      if (value === "(") {
        // 左括号 直接入栈
        opStack.push(token);
      } else if (value === ")") {
        // 右括号: 如果栈非空，那么栈顶元素出栈，直到遇到 左括号；
        while (opStack.length) {
          const topToken = opStack.pop();
          if (topToken.value === "(") {
            break;
          } else {
            queue.push(topToken);
          }
        }
      }
    } else if (type === "operation") {
      // 操作符
      // 如果 "操作符栈" 为空，直接入栈；
      if (opStack.length === 0) {
        opStack.push(token);
      } else {
        //将栈中 "较高和相等" 优先级的操作符放到 后缀表达式中。
        while (true) {
          //终止条件为： 空栈 或者 当前操作符 > 栈顶操作符优先级 或者 优先级相等 并且 栈顶操作符的结合性是 "从右向左"
          if (opStack.length === 0) {
            break;
          }
          const topToken = opStack[opStack.length - 1];
          if (topToken.value === "(") {
            break;
          }
          const opp = opPriority[token.value];
          const topOpp = opPriority[topToken.value];
          if (opp > topOpp) {
            break;
          }
          // 优先级相等 并且 栈顶操作符的结合性是 "从右向左"
          if (opp === topOpp && opRightSet[token.value]) {
            break;
          }
          opStack.pop();
          queue.push(topToken);
        }
        opStack.push(token);
      }
    }
  }

  while (opStack.length) {
    const topToken = opStack.pop();
    queue.push(topToken);
  }

  return queue;
}

function calcSuffix(queue) {
  const stack = [];
  const n = queue.length;
  for (let i = 0; i < n; i++) {
    const token = queue[i];
    if (token.type === "number") {
      stack.push(token);
    } else if (token.type === "operation") {
      if (token.value === "u+" || token.value === "u-") {
        const a = stack.pop();
        const value = opFunMap[token.value](a.value);
        // console.log(value);
        stack.push({ type: "number", value });
      } else {
        const b = stack.pop();
        const a = stack.pop();
        const value = opFunMap[token.value](a.value, b.value);
        // console.log(value);
        stack.push({ type: "number", value });
      }
    }
  }
  // console.log(stack);
  return stack[0].value;
}

/**
 * @param {string} s
 * @return {number}
 */
var calculate = function (s) {
  const tokens = parse(s);
  // console.log(tokens);

  const queue = middle2Suffix(tokens);

  //   console.log(queue);

  const ans = calcSuffix(queue);

  return ans;
};

function test(exp) {
  const ans = calculate(exp);

  console.log(ans);
}

function main() {
  const exp1 = "-( - 123 + (+3213 ))  +10  * 100 /20 / 5 * -2 ";
  test(exp1);

  const exp2 = "1 + 1";
  test(exp2);
}

main();
