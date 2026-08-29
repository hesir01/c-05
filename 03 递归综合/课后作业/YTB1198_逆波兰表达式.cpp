#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、逆波兰（前缀）表达式：运算符在前，运算数在后，例如 * + 11.0 12.0 + 24.0 35.0；
2、递归函数 eval()：
   读入一个字符串 s；
   若 s 是运算符（+ - * /），递归读两个操作数求值后运算；
   若 s 是数字，转成 double 返回；
3、main 调用 eval() 输出结果，保留 6 位小数。
注意：运算数是浮点数，除法按浮点算。
*/
string t;   // 预留（实际在 eval 内局部定义）

// 递归读一个表达式并求值
double eval() {
    string t;
    cin >> t;                               // 读一个 token
    if (t == "+" || t == "-" || t == "*" || t == "/") {
        char op = t[0];                     // 先保存运算符（避免被后续输入覆盖）
        double a = eval();                  // 读左操作数
        double b = eval();                  // 读右操作数
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return a / b;
    }
    return atof(t.c_str());                 // 数字：转浮点数
}

int main() {
    double v = eval();
    printf("%f\n", v);                      // 保留 6 位小数输出
    return 0;
}
