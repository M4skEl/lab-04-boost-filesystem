//
// Created by elisey on 15.12.2020.
//

#ifndef LAB_04_BOOST_FILESYSTEM_LIB_FIN_INF_H
#define LAB_04_BOOST_FILESYSTEM_LIB_FIN_INF_H

#include <set>
#include <string>
#include <ostream>

class Fin_Inf {
 public:
  std::string broker;
  std::string file_type;
  std::string bank_acc;
  std::set<int> dates;

  Fin_Inf();
  Fin_Inf(std::string br,std::string ft,std::string acc,std::set<int> d);
  //void print(const Fin_Inf&);

};

std::ostream& operator <<(std::ostream out, const Fin_Inf& fin);
#endif  // LAB_04_BOOST_FILESYSTEM_LIB_FIN_INF_H
