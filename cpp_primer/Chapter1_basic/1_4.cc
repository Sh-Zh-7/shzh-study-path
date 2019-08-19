#include<iostream>

int main() {
  // 我这里用的是UTF-8编码
  // 而CMD使用的是ANSI/GBK编码
  // 所以控制台会输出乱码
  // 在今后的学习中，尽量使用英文
  int v1, v2;
  std::cout << "请输入两个数" << std::endl;
  std::cin >> v1 >> v2;
  std::cout << v1 << "和" << v2
            << "的乘积是" << v1 * v2
            << std::endl;
  // std::cin不会读入\n，第一个getchar用来处理\n这种垃圾字符
  std::cin.get();
  // 第二个std::cin等待用户输入，用来暂停程序查看结果
  std::cin.get();
  return 0;
}