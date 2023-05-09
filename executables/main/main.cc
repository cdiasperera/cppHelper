#include "main.ih"

// The actual program that will run, during prod
int main(int argc, char *argv[])
try
{
  ArgParser(argc, vector<string>{argv, argv + argc});
}
catch (...)
{
  handleExceptions();
}