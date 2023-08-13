#include "GenOrder.ih"
bool GenOrder::inSameFolder
(
  path const &exRoot, path const &toCheck, path const &toExclude
) const
{
  auto toCheckIterator = toCheck.begin();
  // Get to the actual name of the folder, past the ./setN/exM/ prefix
  for (auto it = exRoot.begin(); it != exRoot.end(); ++it)
    ++toCheckIterator;

  // Compare if folder name matches the toExclude name.
  // Note that toExclude.string() returns toExcludeName/"", hence why we
  // modify *toCheckIterator.
  return (*toCheckIterator/"").string() == toExclude.string();
}
