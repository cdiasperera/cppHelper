#include "main.ih"

int main(int argc, char *argv[])
try
{
  ArgParser(argc, vector<string>{argv, argv + argc});
}
catch (...)
{
  handleExceptions();
}