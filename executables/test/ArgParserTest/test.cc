#include "ArgParserTest.ih"

TEST_F(ArgParserTest, GenFolderTests)
{

  parserTest(genFolderInp, genFolderExp);
  parserTest(genFolderInpNoLoc, genFolderExpNoLoc);
  parserTest(genFolderInpOneReplace, genFolderExpOneReplace);
  parserTest(genFolderInpMulReplace, genFolderExpMulReplace);
  parserTest(genFolderInpMulReplaceMix, genFolderExpReplaceMix);
}