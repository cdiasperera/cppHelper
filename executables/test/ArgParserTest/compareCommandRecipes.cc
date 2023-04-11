#include "ArgParserTest.ih"

bool ArgParserTest::compareCommandRecipes(
  CommandRecipe const &cmdRep1,
  CommandRecipe const &cmdRep2
)
{
  // Check if flags are the same, assuming same number of flags
  for (size_t idx = 0; idx != cmdRep1.flags.size(); idx++)
    if (!compareFlags(cmdRep1.flags[idx], cmdRep2.flags[idx]))
      return false;

  // Check if otherwise similar, also check earlier assumption about num. of
  // flags
  return cmdRep1.cmdType == cmdRep2.cmdType &&
    cmdRep1.args == cmdRep2.args &&
    cmdRep1.flags.size() == cmdRep2.flags.size();
}
