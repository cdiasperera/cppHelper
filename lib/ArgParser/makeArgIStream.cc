#include "ArgParser.ih"

istringstream ArgParser::makeArgIStream(
  size_t argc, vector<string> const &argv
) const
{

  string argString;
  for (size_t argN = argc, idx = 0; idx != argN; ++idx)
    argString += argv[idx] + ' ';

  // Make istream from string
  return istringstream{argString};
}
