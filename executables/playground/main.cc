#include "main.ih"

// A playground executable to work in during development
// Not guaranteed to be stable between merges
int main(int argc, char *argv[])
try
{
  size_t nArgs = argc;
  auto input = vector<string>{argv, argv + argc};
  auto parser = ArgParser{nArgs, input};
  parser.parse();
  CommandRecipe recipe = parser.getCmdRecipe();

  GenOrder genOrder = GenOrder{recipe};

  genOrder.execute();
}
catch (...)
{
  handleExceptions();
}