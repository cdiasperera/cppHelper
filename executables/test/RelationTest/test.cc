#include "RelationTest.ih"

TEST_F(RelationTest, TransitiveTest)
{
  EXPECT_TRUE(rel1.transitiveClosure() == rel1TransClosure);
}

TEST_F(RelationTest, ReflexiveTest)
{
  EXPECT_TRUE(rel1.reflexiveClosure() == rel1RefClosure);
}

// TODO: Add more complex tests
// Test insertion being idempotent, e.g: insert(a,b); insert(a,b);