#include<iostream>
#include<vector>
#include<string>
#include<cassert>
// 不知道为什么，类内不允许使用using指令吗？
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Screen {
 public:
  // 使用useing指定别名
  using pos = std::string::size_type;
  
  Screen() = default;
  Screen(pos height, pos width, string content = " ")
    : height_(height), width_(width) {
      // 注意content必然只包含一个字符
      // 这里是在运行的时候决定其大小, 所以使用assert
      assert(content.size() == 1);
      char ch = content[0];
      // 把content的每一个地方都用content填充
      Fill(ch);
    }
  Screen(pos height, pos width, char ch)
    : height_(height), width_(width) {
    // 注意把string当成像我们vector等其它容器
    // string content_(1, ch); 这个只在初始化时候有用
      Fill(ch);
    }

  Screen &Move(pos x, pos y) {
    cursor_x_ = x; cursor_y_ = y;
    return *this;
  }

  Screen &Set(char ch) {
    content_[cursor_y_][cursor_x_] = ch;
    return *this;
  }


  // 总算明白为什么要返回const&（按理来讲我这里是不详设置返回值的）
  // 因为你是top-level const，所以不可能赋给非const类型的引用
  // 总结就是返回const类型的this时，你就需要使用返回const &
  const Screen &Display() const {
    // 在成员函数嵌套调用的时候
    // this指针会被隐式地传递
    // 比如这里我直接Print就会报错
    // 原因就是我不能把常量引用赋给非常量
    Print();    // 解决方法就是在这里使用const的方法函数
    return *this;
  }

  Screen &Display() {
    Print();
    return *this;
  }

 private:
  // 尝试使用了ch， DRY
  void Fill(char ch) {
  // 填充content
    for (size_t i = 0; i < height_; ++i) {
      string row(width_, ch);
      content_.push_back(row);
    }
  }

  void Print() const {
  // 打印content
    for (const auto &row : content_) {
      for (const auto &col : row) {
        cout << col;
      }
      cout << endl;
    }
  }
  pos cursor_x_ = 0, cursor_y_ = 0;
  pos height_ = 0, width_ = 0;
  vector<string> content_;
};

int main() {
  Screen my_screen(5, 5, "$");
  my_screen.Display();
  my_screen.Move(3, 3).Set('X').Display();
  system("pause>nul");
  return 0;
}