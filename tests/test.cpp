// Copyright 2020 Siver Elisey <sivereliseu7@gmail.com>

#include <Fin_Inf.h>
#include <gtest/gtest.h>

#include <boost/filesystem.hpp>

#include "header.hpp"
#include "sstream"

namespace fs = boost::filesystem;

TEST(Fin_inf, print) {
  std::ostringstream ss;
  Fin_Inf f("broker", "balance", "00001111", {20181010});
  std::string s = "broker: broker account: 00001111files: 1last date: 20181010";
  ss << f;
  EXPECT_EQ(ss.str(), s);
}
