# 关联容器


## 关联容器与顺序容器
关联容器是按关键字来保存和访问的<br>
顺序容器中的元素是按在容器的位置中顺序保存和访问的<br>
<--关键字的左右-->

## 标准库

1：set/map(map:key-value)(set:高效的关键字查询，检查一个关键字是否在set中）
2:要求不重复/重复的关键字（multi)
3:按顺序/无序保存元素(ordered)
4：
## 使用关联容器
code:()

## 关联容器概述
关联容器不支持顺序容器的位置相关的操作(根据关键字存储的）
也不支持构造函数或插入操作这些接受一个元素值和一个数量值的操作
但支持类型别名和无序容器支持哈希调整性能的操作
关联容器的迭代都是双向的

## 管理容器相关操作
通常不对关联容器使用泛型算法，关键字const这一特性意味着不能将关联容器传递给修改或重排容器元素的算法
因为这类算法需要向元素写入值，而set类型的元素是const的，map中的元素的pair，其第一个成员是const的

使用关联容器定义的专用的 find 成员会比调用 泛型 find
快得多

### 插入
insert
### 删除
erase
### 下标操作
set[k]返回关键字为k的元素，不在就添加<br>
set.at[k]访问关键字为 к 的元素，带参数检查；若 к 不在 с 中，抛出一个 out_of_range<br>
异常

### 访问

find/count
对于不允许重复关键字的容器两者没有区别
count会计算
<strong>下标操作可能会添加值</strong>
故用以下
c.find(к) 返回一个迭代器，指向第-个关键字为 к 的元素，若 к 不在容器中，则
返回尾后迭代器<br>
с.count(к) 返回关键字等于к的元素的数量。对于不允许重复关键字的容器，返 回
值永远是 0 或 1<br>
с.lower_bound(к) 返回一个迭代器，指向第一个关键字不小于 к 的元素<br>
с.upper_bound(к) 返回一个迭代器，指向第一个关键字大于 к 的元素<br>
с.equal range(к) 返回一个迭代器 pair,表示关键字等于 к 的元素的范围。若 к 不存 在，
pair 的两个成员均等于 c.end ()<br>

```
string search_item("Alain de Botton”）；//要查找的作者 
auto entries = authors.count(search_item);//元素的数量
auto iter = authors.find(search_item); //此作者的第一本书
//用一个循环查找此作者的所有著作
while(entries) {
cout « iter->second << endl;//打印每个题目
++iter;//前进到下一本书
--entries//记录已经打印了多少本书
```

```
// authors 和 search_item 的定义，与前面的程序一样
// beg 和 end 表示对应此作者的元素的范围
for (auto beg = authors.lower—bound(search—item),end = authors.upper_bound(search_item);
beg != end; ++beg)
cout « beg->second « endl; " 打印每个题目
```
```
for (auto pos =authors.equal_range(search_item); pos.first != pos.second;++pos.first) 
cout << pos.first->second << endl; //
```
## 无序容器(unordered)
由于维护元素的序代价很高，因此使用哈希函数和关键字类型"=="运算符来组织元素
无 序 容 器 使 用 关 键 字 类 型 的 = = 运 算 符 和
一 个 hash<key_type>类塑的对象来组织元素
### 管理桶
无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。无序容器使用一个哈
希函数将元素映射到桶。为了访问一个元素，容器首先计算元素的哈希值，它指出应该搜 索
哪个桶。容器将具有一个特定哈希值的所有元素都保存在相同的桶中。如果容器允许重 复
关键字，所有具有相同关键字的元素也都会在同一个桶中。因此，无序容器的性能依赖 于
哈希函数的质量和桶的数量和大小。
