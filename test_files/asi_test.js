// ASI场景测试

// 场景1: 变量声明后的ASI
var a = 1
var b = 2
var c = a + b

// 场景2: 表达式语句后的ASI
console.log("Hello")
console.log("World")
alert("Test")

// 场景3: return语句后的ASI
function testReturn() {
    return
    42  // 这会被解析为 return; 42;
}

// 场景4: break和continue后的ASI
for (let i = 0; i < 10; i++) {
    if (i === 5) {
        break
    }
    if (i % 2 === 0) {
        continue
    }
    console.log(i)
}

// 场景5: 复合赋值后的ASI
x += 5
y -= 3
z *= 2

// 场景6: 自增自减后的ASI
counter++
index--

// 场景7: 函数调用后的ASI
processData()
updateUI()