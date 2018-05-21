### 元对象系统

Qt 元对象主要用来扩展 c++ 的内省特性.

所谓内省是指面向对象语言的一种在运行期间查询对象信息的能力.

比如如果语言具有运行期间检查对象型别的能力,那么是型别内省(type intropection)，型别内省可以用来实施多态. C++ 是型别内省.

Qt 中的元对象系统全称 Meta Object System，是一个基于标准C++的扩展，为 Qt 提供了信号与槽机制,实时类型信息,动态属性系统.


### 元对象组成

Qt 中的元对象有以下三部分组成:

1.  QObject 类

每一个需要利用元对象系统的类的基类.

2.  Q_OBJECT 宏

定义在每一个类的 private 部分,用来启用元对象功能. 比如动态属性,信号和槽.

在一个 QObject 派生类中,如果没有声明 Q_OBJECT 宏,那么类的 metaobject 对象不会被生成,类实例调用 metaObject() 返回的就是其父类的 metaobject 对象,
导致的后果是从类的实例获得的元数据其实都是父类的数据.所以类所定义和声明的信号和槽都不能使用.

任何从 QObject 继承出来的类,无论是否定义声明了信号,槽和属性,都应该声明 Q_OBJECT   宏.

3. MOC 元对象编译器

MOC 分析 C++ 源文件,如果发现在一个头文件中包含 Q_OBJECT 宏定义，会动态的生成一个 moc_xxxx 命名的C++源文件,
源文件包含Q_OBJECT的实现代码,会被编译和链接到类的二进制代码中,作为类的一部分.

### 元对象功能

#### 运行期间获取信息的方法

QObject::metaObject(): 获得与一个类相关联的 meta-object

QMetaObject::className(): 在运行期间返回一个对象的类名，不需要本地C++编译器的RTTI(run-time type information)支持.

QObject::inherits(): 用来判断生成一个对象类是不是从一个特定的类继承出来，必须是在QObject类的直接或者间接派生类当中.

QObject::tr() and QObject::trUtf8(): 为软件的国际化翻译字符串

QObject::setProperty() and QObject::property(): 根据属性名动态的设置和获取属性值

 qobject_cast(): 在QObject类之间提供动态转换,qobject_cast()方法的功能类似于标准C++的dynamic_cast(),但qobject_cast()不需要RTTI的支持

#### Q_PROPERTY()

```c++
Q_PROPERTY(type name
            READ getFunction
            [WRITE setFunction]
            [RESET resetFunction]
            [NOTIFY notifySignal]
            [REVISION int]
            [DESIGNABLE bool]
            [SCRIPTABLE bool]
            [STORED bool]
            [USER bool]
            [CONSTANT]
            [FINAL])
```

Type:属性的类型

Name:属性的名称

READ getFunction: 属性的访问函数

WRITE setFunction: 属性的设置函数

RESET resetFunction: 属性的复位函数

NOTIFY notifySignal: 属性发生变化的地方发射的notifySignal信号

REVISION int: 属性的版本，属性暴露到QML中

DESIGNABLE bool: 属性在GUI设计器中是否可见，默认为true

SCRIPTABLE bool: 属性是否可以被脚本引擎访问，默认为true

CONSTANT:标识属性的值是常量,值为常量的属性没有 WRITE,NOTIFY

FINAL: 标识属性不会被派生类覆写

#### Q_INVOKABLE

Q_INVOKABLE 宏用于定义一个成员函数可以被元对象系统调用，Q_INVOKABLE宏必须写在函数的返回类型之前.

如下：
```c++
Q_INVOKABLE void invokableMethod();
```

invokableMethod() 函数使用了Q_INVOKABLE宏声明,invokableMethod()函数会被注册到元对象系统中，可以使用 QMetaObject::invokeMethod()调用.

Q_INVOKABLE与QMetaObject::invokeMethod均由元对象系统唤起，在Qt C++/QML混合编程、跨线程编程、Qt Service Framework以及 Qt/ HTML5混合编程以及里广泛使用.

#### 信号和槽

这就不用多说了.


