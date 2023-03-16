## C++ 面向对象的三大特征是：封装、继承、[多态](https://blog.csdn.net/weixin_45897952/article/details/124904764)

1. 封装目的是实现代码模块化 
2. 继承的目的是实现代码的扩展
3. 多态能够使接口重用，增强程序的可扩充性。在程序运行时，根据基类的指针或者引用指向不同类的对象，选择合适的虚函数进行调用。
<table>
  <tbody>
    <tr>
      <td rowspan="2">静态多态(静态绑定、早绑定)</td>
      <td>函数重载</td>
    </tr>
    <tr>
      <td>模板</td>
    </tr>
    <tr>
      <td>动态多态(动态绑定、晚绑定)</td>
      <td>重写</td>
    </tr>
  </tbody>

</table>


[C++内存分配](https://blog.csdn.net/Chroniccandy/article/details/109053967)
[C++内存管理](https://blog.csdn.net/zju_fish1996/article/details/108858577)

<table>
  <tbody>
    <tr>
      <th colspan="3">C++内存布局</th>
    </tr>
    <tr>
      <td rowspan="5" >进程结构</td>
      <td>Stack -- 局部变量、函数参数值、返回变量等</td>
      <td>从高到低</td>
    </tr>
    <tr>
      <td>Heap -- 程序中动态分配的内存</td>
      <td>从低到高</td>
    </tr>
    <tr>
      <td>BSS(Block Started by Symbol) -- 未初始化的全局和静态变量</td>
      <td rowspan="3" >可执行文件结构</td>
    </tr>
    <tr>
      <td>Data Segment --  存放已初始化的全局和静态变量,常量数据</td>
    </tr>
    <tr>
      <td>Code Segment -- 存放可执行程序的机器码。</td>
    </tr>
  </tbody>
</table>

[C++智能指针](https://blog.csdn.net/qq_56673429/article/details/124837626)
1. std::shared_ptr：共享的智能指针
2. std::unique_ptr：独占的智能指针
3. std::weak_ptr：弱引用的智能指针

[bool 与 BOOL的区别](https://blog.csdn.net/gubaofu/article/details/115179096)
BOOL为int型,bool为布尔型;
bool只有一个字节,而BOOL长度视实际编译环境来定，一般可认为是4个字节;
bool取值false和true，是0和非0的区别;,BOOL取值FALSE和TRUE，是0和1的区别;

[同一数组中保存不同类型的数据](http://blog.leanote.com/post/lee-romantic/e78e32f87267)



[html表格生成器](https://c.runoob.com/front-end/7688/)