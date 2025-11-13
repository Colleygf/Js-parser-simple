# JavaScript 语法解析器

一个基于 **C 语言** 的 JavaScript 语法解析器，使用 **re2c** 和 **bison** 构建，支持 **自动分号插入（ASI）机制** 和 **完整的抽象语法树（AST）构建**。

---

## 🚀 项目特性

* ✅ 完整的 JavaScript 语法解析
* ✅ 自动分号插入（ASI）机制
* ✅ 完整的抽象语法树（AST）构建
* ✅ 支持 ECMAScript 基本语法结构
* ✅ 详细的语法错误报告
* ✅ 丰富的测试用例覆盖
* ✅ AST 可视化输出

---

## 🧩 支持的语言特性

### 变量声明

```javascript
var x = 10;
let y = 20;
const z = 30;
```

### 函数

```javascript
function add(a, b) {
    return a + b;
}
```

### 控制流

```javascript
if (condition) { /* ... */ } else { /* ... */ }
while (condition) { /* ... */ }
for (let i = 0; i < 10; i++) { /* ... */ }
```

### 表达式

```javascript
x + y * z
x > 5 ? "greater" : "less"
x === y && y !== z
obj.property
arr[0]
x++
--y
```

### ASI 机制

```javascript
// 自动分号插入
var a = 1
var b = 2
console.log("Hello")
```

---

## 📁 项目结构

```text
js-parser/
├── ast.h              # AST 节点定义
├── ast.c              # AST 构建和操作函数
├── lexer.l            # re2c 词法分析器
├── parser.y           # bison 语法分析器
├── main.c             # 主程序
├── common.h           # 公共类型定义
├── test_files/        # 测试用例目录
│   ├── simple.js
│   ├── asi_test.js
│   ├── error.js
├── Makefile           # 构建配置
```

---

## ⚙️ 构建要求

### 系统要求

* Linux（推荐使用 WSL / Ubuntu）
* gcc 编译器
* make 构建工具

### 依赖工具安装

```bash
sudo apt update
sudo apt install re2c bison build-essential
```

---

## 🧱 构建与安装

### 手动构建

```bash
# 生成词法分析器
re2c -o lexer.c lexer.l

# 生成语法分析器
bison -d -o parser.c parser.y

# 编译可执行文件
gcc -Wall -Wextra -g -o js-parser main.c lexer.c parser.c ast.c -lm
```

### 快速构建（推荐）

```bash
make clean
make
```

---

## 💡 使用方法

### 基本用法

```bash
./js-parser <javascript文件>
```

### 示例

```bash
# 解析单个文件
./js-parser test.js

# 解析测试用例
./js-parser test_files/simple.js

# 测试 AST 构建
./js-parser test_files/ast_test.js

# 手动运行特定测试
./js-parser test_files/asi_test.js
./js-parser test_files/error.js
```

---

## 🧾 输出说明

### 成功解析

```text
Parsing JavaScript file: example.js
✓ Syntax is valid

AST Structure:
Program
  VariableDeclaration: var x
    Number: 10
  ExpressionStatement
    CallExpression
      Identifier: console
      MemberExpression (dot)
        Identifier: log
      String: "Hello World"
```

### 语法错误

```text
Parsing JavaScript file: example.js
PARSER: Syntax error: syntax error
PARSER: At position: 25
PARSER: Context: 'var x = 10 let y = 20'
PARSER:                     ^
✗ Syntax errors found
```

### 调试信息

启用调试输出可以查看详细解析过程：

```text
LEXER: Token VAR at position 3
LEXER: Token IDENTIFIER ('x') at position 5
PARSER: Creating variable declaration node
PARSER: ASI - Automatically inserted semicolon after statement
AST: Built program node with 3 statements
```

---

## 🌳 AST 节点类型

### 表达式节点
- `AST_IDENTIFIER` - 标识符
- `AST_NUMBER` - 数字字面量
- `AST_STRING` - 字符串字面量
- `AST_BOOLEAN` - 布尔字面量
- `AST_BINARY_OP` - 二元运算
- `AST_UNARY_OP` - 一元运算
- `AST_ASSIGNMENT` - 赋值表达式
- `AST_CALL_EXPRESSION` - 函数调用
- `AST_MEMBER_EXPRESSION` - 成员表达式
- `AST_CONDITIONAL_EXPRESSION` - 条件表达式

### 语句节点
- `AST_PROGRAM` - 程序根节点
- `AST_VARIABLE_DECLARATION` - 变量声明
- `AST_FUNCTION_DECLARATION` - 函数声明
- `AST_EXPRESSION_STATEMENT` - 表达式语句
- `AST_BLOCK_STATEMENT` - 块语句
- `AST_IF_STATEMENT` - if 语句
- `AST_WHILE_STATEMENT` - while 语句
- `AST_FOR_STATEMENT` - for 语句
- `AST_RETURN_STATEMENT` - return 语句

---

## ⚙️ 技术细节

### 词法分析器（`lexer.l`）
* 使用 **re2c** 生成高效的词法分析器
* 支持 Unicode 字符
* 处理注释、字符串、数字字面量
* 识别 JavaScript 关键字和运算符

### 语法分析器（`parser.y`）
* 使用 **bison** 生成 LALR 语法分析器
* 实现完整的表达式优先级与结合性
* 支持自动分号插入机制
* 构建完整的抽象语法树
* 提供详细的错误恢复与报告

### AST 构建（`ast.h` / `ast.c`）
* 完整的内存管理（分配和释放）
* 递归 AST 打印功能
* 支持所有主要 JavaScript 语法结构
* 包含源代码位置信息（行号、列号）

### ASI 实现规则

根据 ECMAScript 规范，自动插入分号的情况包括：

1. 行结束符后且语法不允许继续时
2. `}` 符号前
3. 程序结束时

---

## 🧪 测试覆盖

项目包含全面的测试用例：

* **基础语法**：变量、函数、控制流
* **AST 构建**：各种语法结构的 AST 生成
* **ASI 场景**：各种分号省略情况
* **错误情况**：语法错误检测

---

## ⚠️ 限制与注意事项

* 专注于语法验证和 AST 构建而非代码执行
* 某些高级 ES6+ 特性暂不支持
* 错误恢复机制较为基础
* AST 目前主要用于分析和可视化，不包含语义分析

---

## 🧭 开发指南

### 添加新的语法特性

1. 在 `lexer.l` 中添加新的词法规则
2. 在 `parser.y` 中添加对应语法规则
3. 在 `ast.h` 中定义新的 AST 节点类型
4. 在 `ast.c` 中实现节点创建和释放函数
5. 更新优先级和结合性定义
6. 添加测试用例
7. 运行测试验证

### 调试技巧

* 使用 `make clean && make` 重新构建
* 查看详细的 LEXER 和 PARSER 输出
* 使用 AST 打印功能检查语法树结构
* 使用 `-g` 编译启用调试信息
* 检查 bison 的冲突警告

---

## 📜 许可证

本项目仅用于教育与学习目的。

---

## 🤝 贡献

欢迎提交 **Issue** 或 **Pull Request** 来改进本解析器。

---

## 🔗 相关资源

* [ECMAScript 规范](https://tc39.es/ecma262/)
* [re2c 文档](https://re2c.org)
* [Bison 文档](https://www.gnu.org/software/bison/)
* [AST 概念介绍](https://en.wikipedia.org/wiki/Abstract_syntax_tree)

> ⚠️ 注意：本解析器主要用于学习语法分析技术，不建议用于生产环境。

---

## 🎯 下一步计划

* 添加语义分析阶段
* 实现符号表和作用域管理
* 支持更多 ES6+ 特性（箭头函数、类等）
* 添加代码生成功能
* 开发 AST 遍历和转换工具