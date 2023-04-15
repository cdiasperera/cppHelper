#include "ArgParserTest.ih"

bool ArgParserTest::compareCommandRecipes(
  CommandRecipe const &cmdRep1,
  CommandRecipe const &cmdRep2
)
{
  // Check if flags are the same, assuming same number of flags
  for (size_t idx = 0; idx != cmdRep1.d_flags.size(); idx++)
    if (!compareFlags(cmdRep1.d_flags[idx], cmdRep2.d_flags[idx]))
      return false;

  // Check if otherwise similar, also check earlier assumption about num. of
  // flags
  return cmdRep1.d_cmdType == cmdRep2.d_cmdType &&
         cmdRep1.d_args == cmdRep2.d_args &&
         cmdRep1.d_flags.size() == cmdRep2.d_flags.size();
}
