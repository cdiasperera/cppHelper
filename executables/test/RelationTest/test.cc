#include "RelationTest.ih"

TEST_F(RelationTest, TransitiveTest)
{
  rel1.transitiveClosure() == rel1TransClosure;
}
