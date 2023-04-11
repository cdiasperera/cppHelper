#include "ArgParserTest.ih"

void parserTest(vector<string> input, CommandRecipe expected)
{
  ArgParser parser1{input.size(), input};
  EXPECT_EQ(parser1.parse(), 0);
//  EXPECT_TRUE(
//    compareCommandRecipes(
//      parser1.getCmdRecipe(),
//      expected
//    )
//  );
}
