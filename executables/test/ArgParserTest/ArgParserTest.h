#ifndef ARGPARSERTEST_h_1681232185
#define ARGPARSERTEST_h_1681232185

#include "../../../lib/ArgParser/ArgParser.h"

#include <gtest/gtest.h>

class ArgParserTest : public ::testing::Test
{
  using vs = std::vector<std::string>;

  protected:
    // General format of test data will be as follows:

    // Test input
    vs spaceInTextInp = {"cppHelper", "-g", "This is a folder", "1", "1", "8"};
    // Expected test output
    CommandRecipe spaceInTextExp = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {},
      {"This is a folder", "1", "1", "8"}
    };

    vs genFolderInp = {"cppHelper", "-g", "./", "1", "1", "8"};
    CommandRecipe genFolderExp = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {},
      {"./", "1", "1", "8"}
    };

    vs genFolderInpNoLoc = {"cppHelper", "-g", "1", "1", "8"};
    CommandRecipe genFolderExpNoLoc = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {},
      {"1", "1", "8"}
    };

    vs genFolderInpOneReplace = {
      "cppHelper", "-g", "-R", "a", "b", "/", "1", "1", "8"
    };
    CommandRecipe genFolderExpOneReplace = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {
        {'R', {"a", "b"}}
      },
      {"/", "1", "1", "8"}
    };

    vs genFolderInpMulReplace = {
      "cppHelper", "-g", "-R", "a", "b", "-R", "b", "c",
      "./", "1", "1", "8"
    };
    CommandRecipe genFolderExpMulReplace = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {
        {'R', {"a", "b"}},
        {'R', {"b", "c"}}
      },
      {"./", "1", "1", "8"}
    };

    vs genFolderInpMulReplaceMix = {
      "cppHelper", "-g", "-R", "a", "b", "-R", "b", "c",
      "./", "1", "1", "8",  "-R", "c", "d"
    };
    CommandRecipe genFolderExpReplaceMix = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {
        {'R', {"a", "b"}},
        {'R', {"b", "c"}},
        {'R', {"c", "d"}}
      },
      {"./", "1", "1", "8"}
    };

    vs genOrderInp = {"/mnt/c/Users/cdper/repos/cppHelper/cmake-build-debug/playground", "-o", "."};

    CommandRecipe genOrderExp = {
      CommandRecipe::CommandType::GEN_ORDER,
      {},
      {"."}
    };

    vs genOrderInpWithExcl = {"cppHelper", "-o", ".", "1", "2", "3"};
    CommandRecipe genOrderExpWithExcl = {
      CommandRecipe::CommandType::GEN_ORDER,
      {},
      {".", "1", "2", "3"}
    };


    vs zipInp = {"cppHelper", "-z", "."};
    CommandRecipe zipExp = {
      CommandRecipe::CommandType::ZIP_SET,
      {},
      {"."}
    };

    vs zipInpWithExcl = {"cppHelper", "-z", ".", "1", "2", "3"};
    CommandRecipe zipExpWithExcl = {
      CommandRecipe::CommandType::ZIP_SET,
      {},
      {".", "1", "2", "3"}
    };

    void parserTest(
      std::vector<std::string> const &input, CommandRecipe const &expected
    ) const ;

  private:
    static bool compareCommandRecipes(
      CommandRecipe const &cmdRep1, CommandRecipe const &cmdRep2
    );
    static bool compareFlags(Flag const &flag1, Flag const &flag2);
};

#endif