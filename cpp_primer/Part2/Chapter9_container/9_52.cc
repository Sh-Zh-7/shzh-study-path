#include<iostream>
#include<stack>
#include<string>
#include<cctype>
#include<stdexcept>
using namespace std;

// void Operate(stack<int> &nums, stack<char> &ops) {
// // 根据stack顶部的符号决定进行加减操作
// // 然后把nums顶部的两个数字弹出，把结果压栈
//   char sigh = ops.top();
//   ops.pop();
//   int a = nums.top();   nums.pop();
//   int b = nums.top();   nums.pop();
//   int result = (sigh == '+')? a + b : b - a;
//   nums.push(result); 
// }

// int main() {
//   string expression;
//   getline(cin, expression);

//   stack<int> nums;
//   stack<char> ops;
//   // for (char ch : expression) {
//   //   if (isdigit(ch)) {
//   //   // 如果这个字符是数字形式，转化为int后压数字栈
//   //     nums.push(ch - 48);
//   //   } else if (ch == ')') {
//   //   // 如果是）,立刻进行操作
//   //     while (ops.top() != '(') {
//   //       Operator(nums, ops);
//   //     }
//   //     // 删除）
//   //     ops.pop();
//   //   } else {
//   //   // 普通的符号，压入符号栈
//   //     ops.push(ch);
//   //   }
//   // }

//   // 上面那段代码不仅有一点小问题
//   // 而且还说明了一个道理
//   // 我们平时把输入当作一个模块，是有原因的
//   // 上面一例就是把边输入边处理的失败品
//   // 你要知道边处理边输入完全可以转化为输入完在处理
//   // 另外一点比较重要的就是有时候我们会对所有的输入做处理
//   // 之后的处理就会更加方便一点

//   // 注意我们这里是从左向右遍历
//   // 先出现的在栈的底部
//   ops.push('(');
//   for (char ch : expression) {
//     if (isdigit(ch)) {
//       nums.push(ch - 48);
//     } else {
//       ops.push(ch);
//     }
//   }
//   ops.push(')');

//   // 这里我又引入了一个临时的栈——用来储存我丢弃的操作符
//   stack<char> temp;
//   while (!ops.empty()) {
//     char ch = ops.top();  ops.pop();
//     if (ch == '(') {
//       while (temp.top() != ')') {
//         Operate(nums, temp);
//       }
//       temp.pop();    // 删除)
//     } else {
//       temp.push(ch);
//     }
//   }

//   cout << nums.top() << endl;

// --------------------------------------------------------------------
// 利用枚举类型+结构体的技巧
enum Type {NUM, ADD, MIUS, LP, RP};

struct Obj {
  // 像这种没用的形参使用首字母来命名就好了
  Obj(Type t, double v = 0.0) : type(t), val(v) {} 
  Type type;
  double val;
};

void DealNums(stack<Obj> &elems, double val) {
// 遇到下一个元素为数值，直接压栈或处理后压栈
  if (elems.empty() || elems.top().type == LP) {    // 现在你知道为什么要加上那个栈位空的条件了把，还有程序中的逻辑运算符是不符合交换律的
  // 遇到左括号的时候
    elems.push(Obj(NUM, val));
  } else if (elems.top().type == ADD) {
  // 遇到前一个为+的时候
    elems.pop();    // 把符号位也给交了
    double cur_top = elems.top().val;    elems.pop();
    elems.push(Obj(NUM, cur_top + val));   
  } else if (elems.top().type == MIUS) {
  // 遇到前一个为-的时候
    elems.pop();    // 把符号为给你交了
    double cur_top = elems.top().val;    elems.pop();
    elems.push(Obj(NUM, cur_top - val));
  }
}

// 我之前的方法是行不通的
// 原因是——如果我硬要把操作符全部压栈
// 那么我在操作的时候先弹出来的一定是后入栈的操作符
// 也就是说我不得不先计算后面的运算
// 但是这是部队的，+-混合运算是没有所谓结合律的
int main() {
// 这里新采用的方法就是边读边压栈
// 刚入栈的，如果能计算——马上处理掉
// 反而有种先进先处理的感觉
  string exp;
  stack<Obj> elems;

  getline(cin, exp);

  size_t i = 0;
  while (i < exp.size()) {
    // 你switch注意作用域的问题，加上一对括号
    switch (exp[i]) {
      case '(': {
        elems.push(LP);
        ++i;
        break;
      }

      case ')': {
        // 删除（），但是保留其中的数值
        elems.pop();
        double temp = elems.top().val;  elems.pop();
        elems.pop();
        elems.push(Obj(NUM, temp));
        ++i;
        break;
      }

      case '+': {
        elems.push(Obj(ADD));   // 这里直接传入ADD也可，相当于类型转换，但是会让人很迷惑
        ++i;
        break;
      }
      case '-': {
        elems.push(Obj(MIUS));
        ++i;
        break;
      }

      default: {
        size_t off;   // 记录第一个非数字的索引
        double val = stod(exp.substr(i), &off);
        i += off;
        DealNums(elems, val);
      }
    }
  }

  // 输出
  cout << elems.top().val << endl;
  system("pause>nul");
  return 0;
}

