// Copyright 2020 Siver Elisey <sivereliseu7@gmail.com>

#include <header.hpp>
void print_finance_information(const Fin_Inf& fin) {
  auto iter = fin.dates.end();
  iter--;
  std::cout << "broker: " << fin.broker << "   account:" << fin.bank_acc
            << "   files: " << fin.dates.size() << "    last date: " << *iter
            << std::endl;
}
