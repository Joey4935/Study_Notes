# C++基础与提高 [BV1uv4y1a787]

应用层面 

1. 系统层软件开发  windows GNOME KDE
2. 服务器程序开发
3. 游戏、网络、分布式、云计算
4. 基础类库、科学计算    MFC/ACE/QT/GTK


C-》C++

C++对C基础语法的扩展

C++ 面向对象(继承、封装、多态)

STL

书籍
c++ Primer
c++ 编程思想
c++ Primer Plus

# C++对C的扩展

## 类型增强

#### 类型检查更严格

```   
    const int a = 10;
    //a = 100;              //错误
    int *p = &a;            //
    *p = 100;
    printf("a = %d\n",a);   //  c中正确 c++则不可
```
C++中 const 类型 不初始化不行

c++中 指针 强制类型转化 都是设计不好

#### 布尔类型
```

```

[](https://blog.csdn.net/gubaofu/article/details/115179096)

c语言中 bool 只是说至少占能包含true false的大小 但是具体大小看编译器自己发挥

C++中 实现 bool 靠枚举 占一个字节

枚举当宏用得了

#### cin & cout

类对象

