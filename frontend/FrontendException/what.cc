#include "FrontendException.ih"

char const *FrontendException::what() const noexcept
{
  return d_msg.c_str();
}
