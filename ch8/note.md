
# IO库

## IO类
iostream
fstream
sstream

不能拷贝或对IO对象赋值
管理输出缓存：
endl:输出当前对象流和一个换行，然后刷新缓存区
flush：输出当前对象流和刷新缓存区，不附加任何额外字符
ends:输出当前对象和一个空字符然后刷新缓存区
当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新
关联的输出流
## 文件输入输出

## string流
