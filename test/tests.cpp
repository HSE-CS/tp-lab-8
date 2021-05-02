// Copyright 2021 GHA Test Team

#include <gtest/gtest.h>

#include "textgen.h"


TEST(textgen, test1) {
	MarkovChain ex1;
	int a = ex1.MakeTableInt("text.txt");
	EXPECT_EQ(2, a);
}
