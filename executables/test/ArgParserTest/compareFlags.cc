#include "ArgParserTest.ih"
bool ArgParserTest::compareFlags(Flag const &flag1, Flag const &flag2)
{
  return flag1.d_flag == flag2.d_flag;
}
