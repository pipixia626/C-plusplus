# 动态内存

动态分配的对象的生存期与 它们在哪里创建是无关的，只有当显式地被释放时，这些对象才会销毁。

## 背景
静态内存用来保存局部 static
对象、类 static 数据成员以及定义在任何函数之外的变量。
栈内存用来保存定义在函数内的非 static 对象。
分配在静态或栈内存中的对象由编译器自动创建和销毁。对于栈对象，仅在其定义的程序块运行时才 存
在；static 对象在使用之前分配，在程序结束时销毁。

除了静态内存和桟内存，每个程序还拥有一个内存池。这部分内存被称作自由空间
(free store)或堆（heap)。

程序用堆来存储动态分配（
dynamically allocate)的对象 ---- 即，
那些在程序运行时分配的对象。动态对象的生存期由程序来控制，也就是说，当动态对象 不
再使用时，我们的代码必须显式地销毁它们。

## 动态内存与智能指针
动态内存的管理是通过一对运算符来完成的：new,在动态内存中为对象 分
配空间并返回一个指向该对象的指针，我们可以选择对对象进行初始化：delete,接 受
一个动态对象的指针，销毁该对象，并释放与之关联的内存

为了更容易（同时也更安全）地使用动态内存，新的标准库提供了两种智能指针（smart
pointer)类型来管理动态对象

### 智能指针和普通指针的区别
负责自动释放所指向的对象
## 三种智能指针
新标准库提供的这两种智能指针的区别在于管理底层指针的方式：

### shared_ptr
shared_ptr:允许多个指针指向同一个对象

最安全的分配和使用动态内存的方法是调用一个名为 make_Shared 的标准库函数

通常使用auto变量来保存make_shared对象
`shared_ptr<int> p5 = make 一 shared<int>();`
### shared_ptr 的拷贝和赋值

当进行拷贝或赋值操作时，每个 shared_ptr 都会记录有多少个其他 shared_ptr 指向相
同的对象
```
auto p = make_shared<int> (42) ; // p 指向的对象只有 p —个引用者 auto q(p);
// p 和 q 指向相同对象，此对象有两个引用者
```
每个 shared_ptr 都有一个关联的计数器，通常称其为引用计数（reference count)。无论何时拷贝一个 shared_ptr,计数器都会递增<br>
当我们给 shared_ptr赋予一个新值或是 shared_ptr 被销毁（例如-个局部的shared_ptr 离开其作用域时，计数器就会递减)<br>
一旦一个 shared_ptr 的计数器变为 0,它就会调用析构函数释放自己所管理的对象：<br>


如果我们不初始化一个智能指针，它就会被初始化为一个空指针。
我们还可以用 new 返回的指针来初始化智能指针：
shared_ptr<double> pi; // shared_ptr 可以指向一个 double shared_ptr<int> p2
(new int (42) ) ; // p2 指向一个值为 42 的 int
  
  ```
shared_ptr<int> pi = new int (1024); //错误：必须使用直接初始化形式
shared_ptr<int> p2 (new int(1024)); // 正确：使用了直接初始化形式
```
#### 使用动态内存的三种原因

1：程序不知道自己需要使用多少对象<br>
2: 程序不知道所需对象的准确类型<br>
3：程序需要在多个对象间共享数据<br>常见原因

### unique_ptr
unique_ptr:独占所指向的对象
### weak_ptr
weak_ptr:弱引用，指向shared_ptr所管理的对象

## 动态数组