#include "free_functions.ih"

void handleExceptions()
{
  try
  {
    rethrow_exception(current_exception());
  }
  catch (std::exception &exec)
  {
    cerr << exec.what() << '\n';
  }
}
