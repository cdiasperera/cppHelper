#include "ArgParserTest.ih"

TEST_F(ArgParserTest, GenFolderTests)
{
  parserTest(genFolderInp, genFolderExp);
  parserTest(genFolderInpNoLoc, genFolderExpNoLoc);
  parserTest(genFolderInpOneReplace, genFolderExpOneReplace);
  parserTest(genFolderInpMulReplace, genFolderExpMulReplace);
  parserTest(genFolderInpMulReplaceMix, genFolderExpReplaceMix);
}

TEST_F(ArgParserTest, GenOrderTests)
{
  parserTest(genOrderInp, genOrderExp);
  parserTest(genOrderInpWithExcl, genOrderExpWithExcl);
}

TEST_F(ArgParserTest, zipTests)
{
  parserTest(zipInp, zipExp);
  parserTest(zipInpWithExcl, zipExpWithExcl);
}
