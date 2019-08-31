#ifndef STRBLOG_H__
#define STRBLOG_H__

#include<memory>
#include<vector>
#include<iostream>
#include<initializer_list>

class StrBlob {
 public:
  using size_type = std::vector<std::string>::size_type;

  // 构造函数
  StrBlob() = default;
  StrBlob(std::initializer_list<std::string> str) 
    : data_(std::make_shared<std::vector<std::string>>(str)) {}   // 注意这里是使用了str的构造函数

  // 大小
  size_type Size() { return data_->size(); }
  bool Empty() { return data_->empty(); }

  // 修改元素
  void push_back(const std::string &str) { data_->push_back(str); }
  void pop_back() { data_->pop_back(); }

  // 访问元素
  std::string &Front() { return data_->front(); }
  std::string &Front() const { return data_->front();}
  std::string &Back() { return data_->back(); }
  std::string &Back() const { return data_->back(); }
 
 private:
  void Check(size_t size, const std::string &msg); 
  std::shared_ptr<std::vector<std::string>> data_;
};

#endif    // STRBLOG_H__ ends