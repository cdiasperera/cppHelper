#include "ArgParser.ih"

void ArgParser::error(char const *msg)
{
  std::cerr << "Syntax error in command\n";
  std::cerr << "Matched string that didn't parse: "
    << d_scanner.matched()<< '\n';
}
