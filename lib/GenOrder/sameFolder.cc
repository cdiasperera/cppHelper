#include "GenOrder.ih"
bool GenOrder::sameFolder(path const &toCheck, path const &toExclude) const
{
  auto toCheckIterator = toCheck.begin();
  // Get past exercise folder prefix
  for (size_t i = 0; i != SIZE_EX_FLDR_PREF; ++i)
    ++toCheckIterator;

  return (*toCheckIterator/"").string() == toExclude.string();
}
