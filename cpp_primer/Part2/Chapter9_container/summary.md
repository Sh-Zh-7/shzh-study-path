## 第九章习题总结
1. 容器之间大小的比较，**必须要求容器的类型和其元素的类型完全一致**。比如正常情况下我double和int是能够直接比较的，但是作为容器类型的一部分，他们之间就不能比较了。**如果硬要进行不同容器，不同元素类型之间的比较，得自定义函数才行**。
2. vector确实不支持push_front，但是如果你硬要把元素插到vector的最前面的话，就要使用insert才行
3. 注意使用cbegin
4. 其实迭代器也有类似顶层const和底层const的区别，**使用const_iterator类型不能对指向的元素进行修改，但自己指向的内容可以改变，相当于底层const；使用iterator自己再加一个const，相当于顶层const，无法进行++等操作。**
5. 数组的元素可以直接初始化给vector和list等容器，这是因为指针和iterator可以相互转换？
6. 想要访问到forward_list的最后一个元素是很困难的，有以下两点原因：
   1. forward_list的迭代器并不支持--操作，所以我们不能通过end方法+（--）来访问最后一个元素。
   2. 同时,forward_list并没有back成员方法。
</br>所以你不得不**维护前一个节点来达到这个目的**。
7. 你要知道capcity的返回值就是在vector在需要重新分配内存之前**所能容纳的最大元素数量**，所以用**reserve分配到的是成员的数量**这句话一点都没错。
8. stack对象的pop方法只有不接受任何参数，返回值也是void类型，可以视为一个procedure。如果你要访问被弹出栈的第一个元素，就要使用top方法来访问。（其实这一点挺麻烦的，比如我要弹出栈的时候一般也要访问弹出的元素，而我这里却不得不使用两条语句来完成）
9. 新标准不强制把类型的声明放在最前面，那我们大可以在使用的时候进行声明——这样我们在要使用类型的时候，IDE会提供尽量少的信息来给我们补全代码。
10. 学到一个新的泛型算法——find_first_not_of
11. 对于一些上下文相关的算法，使用throw来抛出异常。