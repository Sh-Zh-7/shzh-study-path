#ifndef QUERY_H__
#define QUERY_H__

#include<iostream>
#include<iterator>
#include<fstream>
#include<string>
#include<vector>
#include<memory>
#include<map>
#include<set>

class QueryResult;

class TextQuery {
  friend class QueryResult;
 public:
  TextQuery(std::ifstream &infile);
  QueryResult Query(const std::string &word) const;

 private:
  // 变量名字一定要和它的意义息息相关
  std::shared_ptr<std::vector<std::string>> files_;
  std::map<std::string, std::shared_ptr<std::set<int>>> word_line_;
};

class QueryResult {
  // 重载<<
  friend std::ostream &operator<<(std::ostream&, QueryResult);
 public:
  QueryResult(const std::string &word,
              std::shared_ptr<std::vector<std::string>> p,
              std::shared_ptr<std::set<int>> lines); 
 private:
  std::string word_;
  std::shared_ptr<std::vector<std::string>> files_;
  std::shared_ptr<std::set<int>> line_numbers_;
};

#endif  // QUERY_H__ ends