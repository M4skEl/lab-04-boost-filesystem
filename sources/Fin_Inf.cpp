//
// Created by elisey on 15.12.2020.
//

#include "Fin_Inf.h"

Fin_Inf::Fin_Inf() : broker(), file_type(), bank_acc(), dates() {}

Fin_Inf::Fin_Inf(std::string br, std::string ft, std::string acc,
                 std::set<int> d)
    : broker(br), file_type(ft), bank_acc(acc), dates(d) {}

std::ostream& operator<<(std::ostream& out, const Fin_Inf& fin) {
  auto iter = fin.dates.end()--;
  out << "broker: " << fin.broker << " account: " << fin.bank_acc
      << "files: " << fin.dates.size() << "last date: " << *iter;
  return out;
}
