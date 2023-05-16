#include "GenOrder.ih"

path GenOrder::prefPath(path const &fileInExFolder, size_t upto) const
{
  path prefix;

  // Go through each path element (within 'upto' limit), and attach it to
  // the prefix.
  auto filePathIterator = fileInExFolder.begin();
  for (size_t i = 0; i != upto; ++i)
  {
    prefix /= *filePathIterator;
    ++filePathIterator;
  }

  return prefix;
}
