# 经验总结
1. 利用shell指令查看进程的返回值(echo %ERRORLEVEL%或echo $?)
2. 在使用标准库的时候，尽量不要using namespace std; 多用std::
3. 在控制台暂停——两种方式std::cin.get()（在有cin的情况下要有两个，详情请见1_10.cc）当然还有一种就是system("pause>nul")这个就直接把缓冲区中的字符都丢弃了。
4. 使用标准库中istream对象和ostream对象的时候**必须要使用引用**, 不然isn't accessible错误
5. 传入的变量是const引用的时候，我们仍然可以利用它**返回一个普通类型的副本。**
6. 我vscode使用的是UTF-8编码，但是我的CMD使用的确实ANSI/GBK编码，所以会出现乱码。建议以后尽量使用中文。
