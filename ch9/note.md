# 顺序容器

## 顺序容器概述
提供了控制元素存储和访问顺序的能力，这种顺序不依赖于元素的值，而是与元素加入容器时的位置相对应
所有顺序容器都提供了快速顺序访问的能力
在以下方面有不同的性能折中
向容器添加或从容器中删除元素的代价<br>
向非顺序访问容器中元素的代价<br>

### 类型
vector 可变大小数组，支持快速随机访问。在尾部之外的位置插入或者删除元素效率不高
deque 双端队列 支持快速随机访问。在头尾位置插入/删除速度很快
list 双向链表。只支持双向顺序访问。在 list 中任何位置进行插入/删除 操作速度都
很快
forward_list 单向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作 速度都很
快
array 固定大小数组。支持快速随机访问。不能添加或删除元素
string 与 vector 相似的容器，但专门用于保存字符。随机访问快。在尾部 插入/删除速
度快


## 容器库

### 容器类型成员

## 顺序容器操作

迭代器访问顺序：左闭右开
rbegin(),rend()
begin,cbegin区别：
cbegin是c++新标准引入的，用来与auto结合使用，它返回指向容器第一个元素的const迭代器，可以只用来只读地访问容器元素，但不能对容器进行修改。
因此，当不需要写访问时，应该使用cbegin
begin是被重载的，有两个版本，其中一个是const成员函数，返回const迭代器，另一个返回普通迭代器，可以对容器元素修改。

assign将右边运算对象所有元素拷贝到左边运算对象中

除array外，swap不对任何元素进行拷贝、删除或者插入操作，因此可以保证在常熟时间内完成

### 向顺序容器添加元素
emplace_front()
c.empalce_back()
c.push_back()
c.push_front()
c.insert()
### 访问元素
//返回的都是引用
c.front()
c.back()
c.at(n)
c[n]
### 删除元素
c.pop_front()
c.pop_back()
c.erase(p):p->迭代器所指向的元素
c.erase(b,e):删除迭代器b和e所指定范围内的元素
c.clear()
### 特殊的forward_list操作
单链表操作：
list.insert_after
list.earse_after
### 改变容器大小
c.resize(n)
c.reserve(n):预分配空间
### 容器操作可能使迭代器失效

## vector对象是如何增长的
当调用push或insert成员函数时，将元素类型的对象传递给它们，这些对象
拷贝到容器中，当我们调用一个emplace成员函数时，
则是将参数传递元素类型r的构造函数。emplace成员使用这些参数
在容器管理的内存空间中直接构造元素
## 额外的string操作
substr
fing_first_of()
find_last_of()
find()
replace()
find_first_not_of()
s.assign(str，a,b):从a开始b个字符
s.assign("somestring")
s.assign(5,'x')
transform(str.begin(),str.end()，str.begin(),::tolower)
s1.append(s2)//连接
stoi

s1.compare(s2)
## 容器适配器
