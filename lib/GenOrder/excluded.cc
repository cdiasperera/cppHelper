#include "GenOrder.ih"
bool GenOrder::excluded(path const &toCheck) const
{
  path const prefix = prefPath(toCheck, SIZE_EX_FLDR_PREF);
  for (auto const &toExclude : d_config.getIgnoreForOrderPaths())
    if (sameFile(prefix, toCheck, toExclude) || sameFolder(toCheck, toExclude))
      return true;
  return false;
}
