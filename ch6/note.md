# 函数
## 函数基础
## 参数传递
passed by value <br>
called by value <br>
1）指针传递与引用传递的区别：
指针参数传递本质上是值传递，它所传递的是一个地址值。值传递过程中，被调函数的形参作为被调函数的局部变量处理，会在栈中开辟内存空间以存放由主调函数传递进来的实参值，从而形成了实参的一个副本（替身）。值传递的特点是，被调函数对形参的任何操作都是作为局部变量进行的，不会影响主调函数的实参变量的值（形参指针变了，实参指针不会变）。

引用参数传递过程中，被调函数的形参也作为局部变量在栈中开辟了内存空间，但此时存放的是由主调函数放进来的实参变量的地址。被调函数对形参（本体）的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量（根据别名找到主调函数中的本体）。因此特点，被调函数对形参的任何操作都会影响主调函数中的实参变量。

【注:】指针与引用的另一个重要的不同是指针可以被重新赋值以指向另一个不同的对象。但是引用则总是指向在初始化时被指定的对象，以后不能改变。

（2）在C++中，函数的形参，什么时候使用引用？什么时候使用指针？什么时候使用按值传递？

1  针对函数内部只使用传递的值而不做修改
（1）数据对象较小，如内置数据类型或小型结构体，则按值传递
　　void func(int );<br>
（2）数据对象是数组，则只能使用指针，并将指针const指针
　　void func(const int *,int);//第二个参数为数组长度<br>
（3）数据对象是较大的结构体，则const指针或const引用都行
　　struct struc{…};
　　void func(const struc *);
　　或void func(const struc &);<br>
（4）数据对象是类，则使用const引用
　　void func(const string &,);<br>
2  针对函数内部不仅使用传递的值且要做修改的
（1）数据对象是内置数据类型，则使用指针
　　void func(int *);<br>
（2）数据对象是数组，则只能使用指针
　　void func(int *,int);//第二个参数为数组长度<br>
（3）数据对象是结构体，则使用引用或指针
　　struct struc{…};
　　void func(struc *);
　　或void func(struc &);<br>
（3）数据对象是类，则使用引用
　　void func(ostream &);
  
## const 形参和实参
当形参有顶层 const 时，传给它常量对象或者非常量对象都是 可
以的：
void fen (const int i) { /* fen 能够读取 i，但是不能向 i 写值*/ }
## 数组形参
因为不能拷贝数组，所以我们无法以值传递的
方式使用 数组参数。因为数组会被转换成指针，所以当我们为函数传递一个数组时，实
际上传递的 是指向数组首元素的指针

print(const int*);

void print (const int []) ; //可以看出来，函数的意图是作用于一个数组

void print (const int [10] ) ； //这里的维度表示我们期望数组含有多少元素，实际不一定

int i = 0, j[2] = { 〇, l}；
print (&i) ； // 正确：&i 的类型是 int*
print (j); //正确：j 转换成 int*并指向 j [0]

不要返回局部对象的引用或指针 
函数完成后，它所占用的存储空间也随之被释放掉

 C++语言的函数返回值类型可以分为内部类型和自定义类型两大类。
    在函数返回内部类型中不能返回数组类型但可以返回指向数组的指针，同样也可以返回指向函数的函数指针。如果希望返回值可以作为左值（即可以放在赋值操作符左边的）那就必须返回引用类型。
    而在函数返回自定义类型（即返回类类型）中根据是否可作为左值，返回值是否可调用成员函数的不同可分为以下四种情况。
    T：返回类类型
    T f();<br>
    const T f();<br>
    T& f();<br>
    const T& f();<br>
    T f(); 返回一般的类类型，返回的类类型不能作为左值，但返回的类类型可以直接调用成员函数来修改，如function().set_Value(); 返回类类型调用复制构造函数。<br>
    const T f(); 此种类型与上述第一种相同，唯一不同的是返回的类类型不能调用成员函数来修改，因为有const限定符。<br>
    T& f(); 返回类的引用可以作为左值，并且返回的类类型引用可以直接调用成员函数来修改，返回的类类型不会调用复制构造函数。<br>
    const T& f(); 不能作为左值，不能调用成员函数修改，不会调用复制构造函数。<br>
返回引用的函数返回一个左值。因此，这样的函数可用于任何要求使用左值的地方

typedef int arrT[10]//arrT是一个类型别名，它表示的类型是含有10个整数的数组
using arrT=int [10];// func 返回一个指向含有 10 个整数的数组的指针
arrT*func(int i)// func 返回一个指向含有 10 个整数的数组的指针

不使用类型别名：必须记住被定义的名字后面的数组的维度
int arr[10]
int*p1[10]
int (*p2)[10]=&arr

c++ 11 :auto fun(int i)// func 接受一个 int 类型的实参，返固一个指针，该指针指向含有 10 个整数的数组
还有一种情况，如果我们知道函数返回的指针将指向哪个数组，就可以使用 decltype关键字声明返冋类型
int odd[] = {1,3,5,7,9}; 
int Sceven[]= {0,2,4,6,8};
//返回一个指针，该指针指向含有 5 个整教的数组

decltype(odd) *arrPtr(int i)
{
return (i % 2) ? &odd : Sceven; //返回一个指向数组的指针
}
## 函数重载

同一作用域内的函数名字相同形参列表不同称为重载函数overload
编译器找到一个与实参最佳匹配（best match)的函数，并生成调用该函数的代码。
•找不到任何一个函数与调用的实参匹配，此时编译器发出无匹配（no match)的错误信息。
•有多于一个函数可以匹配，但是每一个都不是明显的最佳选择》此时也将发生错误，
称为二义性调用（ambiguouscall)。
## 特殊用途语言特性

名字查找发生在类型检查之前

### 默认实参
tyepdef string::size_type sz;
### 内联函数
函数声明前加inline
避免函数调用的开销（在编译过程就替换了）编译器一般都不支持内联递归调用

### constexpr函数

用于常量表达式，被隐式地指定为内联函数
函数的返回类型以及所有形参的类型都是字面值类型，且函数体中必须有且只有一条return语句
constexpr 函数体内也可以包含其他语句，只要这些语句在运行时不执行任何操作就行

它的多个定义必须完全一致。基于这个原因内联函数和
constexpr 函数通常定义在头文件

### assert(表达式）
assert (expr);
首先对<exрг 求值，如果表达式为假（即 0), assert 输出信息并终止程序的执行。如果 表
达式为真（即非 0)，assert 什么也不做

编译器依次检查每个实参以确定哪个函数是最佳匹配。如果有且只有 一个函数

满足下列条件，则匹配成功：

•该函数每个实参的匹配都不劣于其他可行函数需要的匹配。

•至少有一个实参的匹配优于其他可行函数提供的匹配

## 函数匹配

### 实参类型转换

#### 精确匹配

实参类型和形参类型相同<br>
实参从数组类型或函数类型转换成对应的指针类型<br>
向实参添加顶层const或者从实参中删除顶层const<br>

#### 通过const转换实现的匹配 const_cast(改变运算对象的底层const)，static_cast（改变不包含底层const)
#### 通过类型提升的匹配
#### 通过算数型转换
#### 通过类类型转换
## 函数指针
指向的是函数而非对象，和其他指针一样，函数指针指向某种特定类型
注意重载之后对应的函数参数
