#include "GenFolderTest.ih"

TEST_F(GenFolderTest, SetMainArgumentsTests)
{
  EXPECT_TRUE(GenFolderTest::hasMainArgs(
    genFolderCmd, genFolderCmdExpArgs
  ));
  EXPECT_TRUE(GenFolderTest::hasMainArgs(
    genFolderCmdDefaultLoc, genFolderCmdDefaultLocExpArgs
  ));
}
