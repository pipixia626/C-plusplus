# 重载运算与类型转换


## 运算符

1：输入输出运算符
2：算数和关系运算符
3：赋值运算符
4：下标运算符
5：递增递减运算符
6：成员访问运算符
7：函数调用运算符

逗号和取址运算符最好不要重载（会改变运算顺序）

## 重载、类型转换和运算符

### 避免有二义性的转换

1：两个类提供相同的类型转换
例 如：当A 类定义了一个接受 В 类对象的转换构造函数，同时 В 类定义了一个转换目标是 А 类的类型转换运
算符时，我们就说它们提供了相同的类型转换
2：类定义了多个转换规则
