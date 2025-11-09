JavaScript 语法解析器
一个基于 C 语言的 JavaScript 语法解析器，使用 re2c 和 bison 工具构建，支持自动分号插入（ASI）机制。

项目特性
✅ 完整的 JavaScript 语法解析

✅ 自动分号插入（ASI）机制

✅ 支持 ECMAScript 基本语法结构

✅ 详细的语法错误报告

✅ 丰富的测试用例覆盖

支持的语言特性
变量声明
javascript
var x = 10;
let y = 20;
const z = 30;
函数
javascript
function add(a, b) {
    return a + b;
}
控制流
javascript
if (condition) { /* ... */ } else { /* ... */ }
while (condition) { /* ... */ }
for (let i = 0; i < 10; i++) { /* ... */ }
表达式
javascript
x + y * z
x > 5 ? "greater" : "less"
x === y && y !== z
ASI 机制
javascript
// 自动分号插入
var a = 1
var b = 2
console.log("Hello")
项目结构
text
js-parser/
├── lexer.l           # re2c 词法分析器
├── parser.y          # bison 语法分析器
├── main.c            # 主程序
├── common.h          # 公共类型定义
├── test_files/       # 测试用例目录
│   ├── simple.js
│   ├── asi_test.js
│   ├── error.js
├── Makefile          # 构建配置
构建要求
系统要求
Linux (WSL/Ubuntu 推荐)

gcc 编译器

make 构建工具

依赖工具
bash
sudo apt update
sudo apt install re2c bison build-essential
构建和安装
自动安装依赖和构建
bash
make install-deps
make
手动构建
bash
# 生成词法分析器
re2c -o lexer.c lexer.l

# 生成语法分析器
bison -d -o parser.c parser.y

# 编译可执行文件
gcc -Wall -Wextra -g -o js-parser main.c lexer.c parser.c -lm
快速构建（推荐）
bash
make clean
make
使用方法
基本用法
bash
./js-parser <javascript文件>
示例
bash
# 解析单个文件
./js-parser test.js

# 解析测试用例
./js-parser test_files/simple.js

# 或手动运行特定测试
./js-parser test_files/asi_test.js
./js-parser test_files/error.js
输出说明
成功解析
text
Parsing JavaScript file: example.js
✓ Syntax is valid
语法错误
text
Parsing JavaScript file: example.js
PARSER: Syntax error: syntax error
PARSER: At position: 25
PARSER: Context: 'var x = 10 let y = 20'
PARSER:                     ^
✗ Syntax errors found
调试信息
启用调试输出可以看到详细的解析过程：

text
LEXER: Token VAR at position 3
LEXER: Token IDENTIFIER ('x') at position 5
PARSER: Parsed variable declaration
PARSER: ASI - Automatically inserted semicolon after statement
技术细节
词法分析器 (lexer.l)
使用 re2c 生成高效的词法分析器

支持 Unicode 字符（通过 re2c）

处理注释、字符串、数字字面量

识别 JavaScript 关键字和运算符

语法分析器 (parser.y)
使用 bison 生成 LALR 语法分析器

实现完整的表达式优先级和结合性

支持自动分号插入机制

详细的错误恢复和报告

ASI 实现
根据 ECMAScript 规范，在以下情况自动插入分号：

行结束符后且语法不允许继续时

} 符号前

程序结束时

测试覆盖
项目包含全面的测试用例：

基础语法 - 变量、函数、控制流

ASI 场景 - 各种分号省略情况

错误情况 - 语法错误检测

限制和注意事项
当前版本不构建完整的 AST（抽象语法树）

专注于语法验证而非代码执行

某些高级 ES6+ 特性可能不受支持

错误恢复机制相对基础

开发指南
添加新的语法特性
在 lexer.l 中添加新的词法规则

在 parser.y 中添加相应的语法规则

更新优先级和结合性定义

添加测试用例

运行测试验证

调试技巧
使用 make clean && make 确保重新构建

查看详细的 LEXER 和 PARSER 输出

使用 -g 标志编译以启用调试信息

检查 bison 的冲突警告

许可证
本项目仅用于教育和学习目的。

贡献
欢迎提交 Issue 和 Pull Request 来改进这个解析器。

相关资源
ECMAScript 规范

re2c 文档

Bison 文档

注意：此解析器主要用于学习语法分析技术，不建议用于生产环境。