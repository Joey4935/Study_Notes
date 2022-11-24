## `CString` `Char *` `string`

`CString`用于封装字符串数据结构, 容易使用，功能强，动态分配内存，大量进行拷贝时它很能节省内存资源并且执行效率高，与标准C完全兼容。同时支持==多字节==与==宽字节==由于有异常机制所以使用它安全方便。

#### `CString` 的实现机制
`CString`是通过“引用”来管理分配的内存块。CString对象只有一个指针成员变量，这个指针指向一个相关的引用内存块，所以任何CString的实例长度只有4字节。
`int len = sizeof(CString); // len == 4`

```
CString str("abcd");
CString a = str;
CString b(str);
CString c;
c = b;
```
这段代码中 a,b,c,str中的==成员变量指针==的值相同。

引用内存块的结构定义如下
```
struct CStringData
{
    long nRefs;         //表示有多少个CString 引用它. 4
    int nDataLength;    //串实际长度. 4
    int nAllocLength;   //总共分配的内存长度（不计这头部的12字节）. 4
};
```

#### `LPCTSTR` 与 `GetBuffer(int nMinBufLength)`

