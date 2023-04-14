#ifndef GENFOLDERTEST_h_1681465973
#define GENFOLDERTEST_h_1681465973

#include "../../../lib/GenFolder/GenFolder.h"

#include <gtest/gtest.h>

#include <tuple>

class GenFolderTest : public ::testing::Test
{
  using ExpectedArgs = std::tuple<std::string, size_t, size_t, size_t>;
  enum
  {
    SET_ARG_POS_EXP_ARGS = 1,
    EXSTART_ARG_POS_EXP_ARGS,
    EXEND_ARG_POS_EXP_ARGS
  };

  protected:
    GenFolder genFolderCmdDefaultLoc{
      {
        CommandRecipe::CommandType::GEN_FOLDER,
        {},
        {"1", "1", "8"}
      }
    };
    ExpectedArgs genFolderCmdDefaultLocExpArgs = {".", 1, 1, 8};

    GenFolder genFolderCmd{
      {
        CommandRecipe::CommandType::GEN_FOLDER,
        {},
        {"./Exercises", "1", "1", "8"}
      }
    };
    ExpectedArgs genFolderCmdExpArgs = {"./Exercises", 1, 1, 8};

    static bool hasMainArgs(
      GenFolder const &genFolder,
      ExpectedArgs const &expectedArgs
    );
};

#endif
