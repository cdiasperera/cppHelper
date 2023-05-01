#include "RelationTest.ih"
RelationTest::RelationTest()
{
  rel1.relate("a", "b");
  rel1.relate("b", "c");

  rel1TransClosure.relate("a", "b");
  rel1TransClosure.relate("b", "c");
  rel1TransClosure.relate("a", "c");

  rel1RefClosure.relate("a", "b");
  rel1RefClosure.relate("b", "c");
  rel1RefClosure.relate("a", "a");
  rel1RefClosure.relate("b", "b");
  rel1RefClosure.relate("c", "c");
}
