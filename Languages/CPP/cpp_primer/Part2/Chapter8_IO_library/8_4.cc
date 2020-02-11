#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int main() {
  std::ifstream ifile(".\\Chapter8_IO_library\\1.txt");
  if (!ifile) {
    std::cerr << "Cann't open file!\n";
    return -1;
  }
  std::vector<std::string> my_vector;
  std::string temp;
  while (ifile >> temp) {
    my_vector.push_back(temp);
  }
  ifile.close();
  for (const auto &i : my_vector) {
    std::cout << i << std::endl;
  }
  system("pause>nul");
  return 0;
}     
