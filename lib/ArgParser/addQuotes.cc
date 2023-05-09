#include "ArgParser.ih"
vector<string> ArgParser::addQuotes(vector<string> const &argv)
{
  vector<string> quotedVector;
  for (auto arg: argv)
  {
    if (arg.contains(' '))
    {
      arg.insert(0, "\"");
      arg += '\"';
    }
    quotedVector.push_back(arg);
  }

  return quotedVector;
}
