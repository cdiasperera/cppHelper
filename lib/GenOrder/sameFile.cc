#include "GenOrder.ih"
bool GenOrder::sameFile(
  path const &exPrefix, path const &toCheck, path const &toExclude
) const
{
  return exPrefix/toExclude == toCheck;
}