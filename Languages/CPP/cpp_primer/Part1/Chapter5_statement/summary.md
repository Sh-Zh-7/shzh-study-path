## 第五章习题总结
1. 没想到**while()里面竟然可以和int一样放声明**（返回值呢？好奇怪啊），而且它的**作用域还延伸到它所属的块中**。但是每**次循环都会重新创建。**
2. C++**字符串之间可以相比**（利用字典序）；C++**字符串中的字符也可以相比**，因为字符本质上就是整型。——这些都很和谐，唯一不和谐的就是字符串用augment assignment时不能添加const char类型，的，只能添加const char*类型的。
3. 关于数组与函数的映射——我想了一下这个东西其实还是比较灵活的。所以我专门写了一个blog, 放在my_blog文件夹中。
4. cin.get()完全可以用char ch; cin >> ch；来替代(cin.get()是重载的方法，有一种使用方法是完全与getchar等同，还有一种常用的cin.get(ch));
5. 关于switch的写法：switch后面不需要直接跟：,跟的是{}， case label和default label后面跟的才是:
6. 根据编程习惯，我们可能会再switch后面加一句空的default:，最好把break也加上，不然就是default: }，编译无法通过。
7. 我好像明白为什么要给switch添加code snippet了，这是因为我们手动添加case，代码会不断缩进，比较麻烦。
8. 在做practice的时候，我总算明白cin.clear()和cin.sync()的意义所在了，比如我们要输入两行数据，但是编译器之后会把它当作一行的数据流，作为practice我们就可以把EOF当作是行结束的标志，此时把cin转为bool的时候就会变成false。要使用cin.clear()+cin.sync()清除缓冲区。
9. 5_19.cc向我们说明了do...while的劣势，并让我初步使用了freopen；
10. 看看5_25