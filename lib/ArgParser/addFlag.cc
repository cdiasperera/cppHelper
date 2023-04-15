#include "ArgParser.ih"
void ArgParser::addFlag(char flag, ArgParser::StrIniList const &args)
{
  d_cmdRecipe.d_flags.emplace_back(flag, args);
}
