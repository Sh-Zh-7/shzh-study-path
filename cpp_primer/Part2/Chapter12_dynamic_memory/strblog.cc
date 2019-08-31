#include"strblog.h"
#include<string>
#include<stdexcept>
using namespace std;

void StrBlob::Check(size_t size, const string& msg) {
  if (size <= 0) {
    throw out_of_range(msg);
  }
}