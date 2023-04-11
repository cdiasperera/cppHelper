#include "ArgParser.ih"
ArgParser::ArgParser(size_t argc, vector<string> const &argv)
  : d_argIStream(makeArgIStream(argc, argv)),
    d_scanner(d_argIStream)
{}
