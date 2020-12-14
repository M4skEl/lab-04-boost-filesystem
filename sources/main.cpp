// Copyright sivereliseu7@gmail.com 2020
// Created by elisey on 14.12.2020.
//
#include <boost/filesystem.hpp>
#include <iostream>

namespace fs= boost::filesystem;
int main(int argc, char* argv[]) {

  fs::path path_to_ftp;
  if(argc>1) path_to_ftp=argv[1];
  else path_to_ftp=fs::current_path();

  if(!fs::exists(path_to_ftp))


  std::cout << "let's go" << std::endl;
  return 0;
}