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
    vs genFolderInp = {"cppHelper", "-g", "\"/\"", "1", "1", "8"};
    // Expected test output
    CommandRecipe genFolderExp = {
      CommandRecipe::CommandType::GEN_FOLDER,
      {},
      {"\"/\"", "1", "1", "8"}
    };

    vs genFolderInpNoLoc = {"cppHelper", "-g", "1", "1", "8"};
    CommandRecipe genFolderExpNoLoc = {};

    vs genFolderInpOneReplace = {
      "cppHelper", "-g", "-R", "\"a\"", "\"b\"", "\"/\"", "1", "1", "8"
    };
    CommandRecipe genFolderExpOneReplace = {};

    vs genFolderInpMulReplace = {
      "cppHelper", "-g", "-R", "\"a\"", "\"b\"", "-R", "\"b\"", "\"c\"", "\"/\"", "1", "1", "8"
    };
    CommandRecipe genFolderExpMulReplace = {};

    vs genFolderInpMulReplaceMix = {
      "cppHelper", "-g", "-R", "\"a\"", "\"b\"", "-R", "\"b\"", "\"c\"", "\"/\"", "1", "1", "8",
      "-R", "\"c\"", "\"d\""
    };
    CommandRecipe genFolderExpReplaceMix = {};

    bool compareCommandRecipes(CommandRecipe const &cmdRep1, CommandRecipe const &cmdRep2);
  private:
    bool compareFlags(Flag const &flag1, Flag const &flag2);
};

#endif