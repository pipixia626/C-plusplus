# 条款1~10

## 视C++为一个语义联邦

1:C C++仍是以C为基础，区块，语句，预处理器，内置数据类型，数组，指针都是来自C

2:Object-Oriented C++ :构造函数和析构函数，封装，继承，多态

3：Template c++:泛型编程的部分

4：STL: STL是个templaye程序库，对容器，迭代器，算法和函数对象的规约有着极佳的紧密配合和协调

## 尽量以const ,enum,inline 替换#define

宁可以编译器替换处理器
#define不视为语言的一部分

#define不注重作用域（scope）一旦宏被定义，它在其后的编译过程中有效，因此不提供任何封装性
而const可以被封装的
对于形似函数的宏，最好改用inline函数替换#define

## 尽可能使用const


关键字const出现在 星号左边，表示被指物是常量，出现在指针右边，表示指针自身是常量
两者可以同时出现

STL迭代器以指针为根据塑膜出来，所以迭代器的作用像个T* 指针声明迭代器为const-> T* const
表示这个迭代器不得指向不同类型的东西，但它指向的东西的值是可以改动的，如果期望迭代器所指向的东西不可以改动
const T*

const 最具威力：面对函数声明时的应用

函数返回值：返回一个常量值，降低因客户错误而造成的意外

各参数：

函数自身(成员函数）：确认该成员函数可作用于const对象身上
1：使class接口比较容易被理解，得知哪个函数可以改动对象内容，哪个不行

2：操作const对象变成可能 pasy-by-reference方式传递对象变得可能（前提是有const对象）

## 确定对象使用前已被初始化

### 赋值和初始化
对象的成员变量的初始化动作发生在进入构造函数体之前，这样效率会更高
因为比起调用default函数然后再调用copy assigment操作符，单次调用copy构造函数会更高
```
ABEntry: :ABEntry(const std: :string& ne const std: :string& address,
const std::1 st<PhoneNumber>& phones)
:theNarne(narne) ,
theAddress(address) , //现在，这些都是初始化 (initializations )
thePhones(phones) ,
numTimesConsu1ted(O)//构造函数本体不必有任何动作
( }
```



