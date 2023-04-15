#include "ArgParser.ih"
void ArgParser::addArguments(ArgParser::StrIniList const &args)
{
  for (const auto &arg: args)
    d_cmdRecipe.d_args.push_back(arg);
}
