#ifndef RELATIONTEST_h_1682955791
#define RELATIONTEST_h_1682955791

#include "../../../lib/Relation/Relation.h"

#include <gtest/gtest.h>

class RelationTest : public ::testing::Test
{
  using StringRel = Relation<std::string>;
  protected:
    StringRel rel1;
    StringRel rel1TransClosure;
};

#endif
