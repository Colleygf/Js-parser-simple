// 基础语法测试
var x = 10;
let y = 20;
const z = 30;

// 函数声明和调用
function add(a, b) {
    return a + b;
}

var result = add(5, 3);

// 条件语句
if (x > 5) {
    console.log("x is greater than 5");
} else if (x === 5) {
    console.log("x is equal to 5");
} else {
    console.log("x is less than 5");
}

// 循环语句
for (let i = 0; i < 5; i++) {
    console.log("Iteration:", i);
}

while (x > 0) {
    x--;
}

// 表达式
var sum = x + y * z;
var isTrue = (x > 0) && (y < 100);
var max = x > y ? x : y;