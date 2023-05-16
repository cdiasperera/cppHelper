#include "ArgParser.ih"
void ArgParser::addArguments(StrIniList const &args)
{
  for (const auto &arg: args)
    d_cmdRecipe.d_args.push_back(arg);
}
