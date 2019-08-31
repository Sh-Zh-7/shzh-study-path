#include"query.h"
#include<sstream>

TextQuery::TextQuery(std::ifstream &infile) 
    : files_(new std::vector<std::string>) {
// 从传入的文件中构造map和vector
  std::string line;
  while (getline(infile, line)) {
    // 从0开始的行号统计
    // 注意这里不需要额外使用变量来追踪行号
    // 要充分利用容器本身的数据
    int line_count = files_->size();
    files_->push_back(line);

    std::istringstream line_stream(line);
    std::string word;
    while (line_stream >> word) {
      auto &count = word_line_[word];
      if (!count) {
        // 指针本身就有方法, 解引用只不过是其中一种操作罢了
        count.reset(new std::set<int>);
      } 
      count->insert(line_count);
    }
  }
} 

QueryResult TextQuery::Query(const std::string &word) const {
// 从map中搜寻函数，找到就返回QueryResult类型变量
  auto loc = word_line_.find(word);
  if (loc == word_line_.end()) {
    throw std::runtime_error("No such word!\n");
  } else {
    // 把能copy的数据全部copy了
    // 由于我们之前都是使用指针啥的
    // 所以这里就算是copy也不会有太大的开销
    return QueryResult(word, files_, loc->second);
  }
}

// ------------------------------------------------------
QueryResult::QueryResult(const std::string &word,
                         std::shared_ptr<std::vector<std::string>> file,
                         std::shared_ptr<std::set<int>> lines)
    : word_(word), files_(file), line_numbers_(lines) {}

std::ostream &operator<<(std::ostream& out, const QueryResult qr) {
  out << qr.word_ << " occurs " << qr.line_numbers_->size() << " times\n";
  // 需要使用迭代器所指向的值的时候，需要使用*解引用
  for (const auto &i : *qr.line_numbers_) {
    out << "\t(line " << i + 1 << ") " << *(qr.files_->begin() + i) << std::endl; 
  }
  return out;
}     