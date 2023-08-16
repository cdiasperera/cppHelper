#include "CLI.ih"
void CLI::handleException(exception const &exception) const
{
  cerr << usage();

  cerr << "CLI parsing error" << '\n'
    << exception.what() << '\n';

  throw exception;
}
