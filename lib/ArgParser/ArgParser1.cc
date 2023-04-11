#include "ArgParser.ih"
ArgParser::ArgParser(int argc, char *argv[])
{
  stringstream argStream;
  for (size_t argN = argc, idx = 0; idx != argN; ++idx)
    argStream << argv[idx];

  d_scanner = ArgScanner(argStream, cerr);
}
