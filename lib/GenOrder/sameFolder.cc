#include "GenOrder.ih"
bool GenOrder::sameFolder(path const &toCheck, path const &toExclude) const
{
  auto toCheckIterator = toCheck.begin();
  // Get to the actual name of the folder, past the ./setN/exM/ prefix
  for (size_t i = 0; i != SIZE_EX_FLDR_PREF; ++i)
    ++toCheckIterator;

  // Compare if folder name matches the toExclude name.
  // Note that toExclude.stirng() returns toExcludeName/"", hence why we
  // modify *toCheckIterator.
  return (*toCheckIterator/"").string() == toExclude.string();
}
