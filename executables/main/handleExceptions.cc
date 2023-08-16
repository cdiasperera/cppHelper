#include "main.ih"

enum
{
  NOERROR,
  ERROR
};

int handleExceptions()
try
{
  rethrow_exception(current_exception());
}
catch (exception &exception)
{
  return ERROR;
}

