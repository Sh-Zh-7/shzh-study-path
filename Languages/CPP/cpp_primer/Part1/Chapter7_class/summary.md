## 第七章习题总结
---
### 关于value, reference, const reference
---**在parameter中的状况**
1. 对于primitive types，我们一般都是pass by value
2. 首先对于比较大的类类型，或者是容器，**一般我们都传引用**
3. 至于加不加const，<font color="red">**最合理的办法就是看需不需要修改**</font>——如果确定不修改，要加const，那就会有很多额外的好处（字面量啊，包括非const类型的量都可以传进来了）
  
---**在return中的状况**</br>
首先要了解到—— 如果返回的是引用，**注意到绝不可能是局部变量的引用，所以该引用只能绑定参数中的引用。**</br>
<font color="red">**判断返回是value还是reference的一般方法——是决定是不是传副本。**</br></font>
如果返回是副本，那么用value(比如重载=)</br>
如果返回的是左值，那么用reference value(比如重载+=)</br>
(这里和下面的---相接的话不知道为什么就放大了)

----------
## 其它总结
1. 使用copy cntr的优势：
   1. 由于它接受的是const reference, 所以可以接受const和non-const的变量
   2. 没有明确给出返回值，这样就诞生了很tricky的技巧——利用top level const的对象产生non-const的对象（详见=的重载）
2. 记住class后面要跟分号（；），不然会出现很诡异的错误。
3. 一定要搞清楚自己写的程序会发生什么状况——比如书上的那个例程，是不会输出最后一个SalesItem的实例的（习题集上有，但是原书上没有）。
4. char与string类型之间的相互转换一定要记清楚了——通过char的push_back组成string，通过string的访问来获取char
5. 注意string的骚操作——把它当成一个普通的容器类型来使用。
