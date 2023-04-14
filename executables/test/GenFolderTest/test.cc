#include "GenFolderTest.ih"

TEST_F(GenFolderTest, SetMainArgumentsTests)
{
  GenFolderTest::hasMainArgs(
    genFolderCmd, genFolderCmdExpArgs
  );
  GenFolderTest::hasMainArgs(
    genFolderCmdDefaultLoc, genFolderCmdDefaultLocExpArgs
  );
}
