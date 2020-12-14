// Copyright sivereliseu7@gmail.com 2020
// Created by elisey on 14.12.2020.
//
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>

#include "Fin_Inf.h"

using std::cin;
using std::cout;
using std::endl;

namespace fs = boost::filesystem;
int main() {

  fs::path path_to_ftp = "../FTP";

  /*if(argc>1) path_to_ftp=argv[1];
  else path_to_ftp=fs::current_path();
*/
  // if(!fs::exists(path_to_ftp))

  fs::path internal_path;
  fs::path files;
  std::string str;

  for (const auto& iter : fs::directory_iterator{path_to_ftp}) {
    // std::cout<<iter.path()<<std::endl;
    internal_path = iter.path();
    cout << internal_path.filename() << endl;

    for (const auto& internal : fs::directory_iterator{internal_path}) {
      // std::cout << internal.path().filename() << std::endl;
      // files=internal.path();
      size_t j = 0;
      str = internal.path().stem().string();
      if (str.find("old") != std::string::npos) continue;
      while (str[j] != '_') {
        j++;
        str[j];
      }
      cout << str << endl;
    }
  }

  return 0;
}