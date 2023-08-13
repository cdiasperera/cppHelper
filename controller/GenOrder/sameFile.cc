#include "GenOrder.ih"
bool GenOrder::sameFile(
  path const &exRoot, path const &toCheck, path const &toExclude
) const
{
  return exRoot/toExclude == toCheck;
}