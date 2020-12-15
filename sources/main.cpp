// Copyright sivereliseu7@gmail.com 2020
// Created by elisey on 14.12.2020.
//
#include <boost/filesystem.hpp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "Fin_Inf.h"
#include "header.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace fs = boost::filesystem;

int main(int argc, char* argv[]) {
  fs::path path_to_ftp;
  //= "../FTP";

  if (argc > 1)
    path_to_ftp = argv[1];
  else
    path_to_ftp = fs::current_path();

  if (fs::exists(path_to_ftp)) {
    fs::path internal_path;
    fs::path files;
    std::string str_buf;
    std::map<std::pair<string, string>, Fin_Inf> finance;

    cout << "ALL Finance files:" << endl;

    for (const auto& iter : fs::directory_iterator{path_to_ftp}) {
      internal_path = iter.path();

      for (const auto& internal : fs::directory_iterator{internal_path}) {
        Fin_Inf fin_list;
        fin_list.broker = internal_path.filename().string();

        str_buf = internal.path().filename().string();
        if (str_buf.find("old") != std::string::npos) continue;

        std::stringstream ss;
        ss << str_buf;

        std::getline(ss, fin_list.file_type, '_');

        if (fin_list.file_type != "balance") continue;

        std::getline(ss, fin_list.bank_acc, '_');

        std::getline(ss, str_buf, '.');

        cout << fin_list.broker << " " << fin_list.file_type << "_"
             << fin_list.bank_acc << "_" << str_buf << ".txt" << endl;

        //проверка есть ли уже файлы для данного аккаунта
        std::pair<string, string> broker_key;
        broker_key.first = fin_list.broker;
        broker_key.second = fin_list.bank_acc;
        if (finance.count(broker_key)) {
          finance[broker_key].dates.insert(atoi(str_buf.c_str()));
        } else {
          fin_list.dates.insert(atoi(str_buf.c_str()));
          finance[broker_key] = fin_list;
        }
      }
    }
    cout << endl << "Files of each brokers" << endl;
    for (const auto& j : finance) {
      print_finance_information(j.second);
    }
  } else {
    throw std::invalid_argument("wrong in path name");
  }
  return 0;
}
