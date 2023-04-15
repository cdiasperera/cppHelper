#include "ArgParserTest.ih"

void ArgParserTest::parserTest(
  vector<string> const &input,
  CommandRecipe const &expected
) const
{
  ArgParser parser{input.size(), input};
  EXPECT_EQ(parser.parse(), 0);
  EXPECT_TRUE(
    ArgParserTest::compareCommandRecipes(
      parser.getCmdRecipe(),
      expected
    )
  );
}
