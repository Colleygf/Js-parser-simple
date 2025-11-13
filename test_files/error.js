// 预期会报错的测试用例

// 1. 语法错误 - 缺少括号
//function missingParen(a, b {
    //return a + b;
//}

// 2. 语法错误 - 缺少分号（在不能ASI的地方）
//ar x = 1
//[1, 2, 3].forEach(console.log)  // 如果没有ASI，这会报错

// 3. 语法错误 - 无效的token
var @invalid = 10;

// 4. 语法错误 - 不完整的表达式
var y = 5 +;

// 5. 语法错误 - 不匹配的括号
if (x > 5 {
    console.log("Missing closing parenthesis");
}

// 6. 语法错误 - 无效的转义字符
var str = "Invalid \z escape";

// 7. 语法错误 - 重复的变量声明
var x = 10;
let x = 20;  // 重复声明（在严格模式下报错）

// 8. 语法错误 - 无效的break/continue
function invalidBreak() {
    break;  // break不在循环内
}

// 9. 语法错误 - 参数列表错误
function invalidParams(a, b,, c) {
    return a + b + c;
}

// 10. 语法错误 - 对象字面量错误
var obj = {
    prop: "value"
    anotherProp: "value2"  // 缺少逗号
};