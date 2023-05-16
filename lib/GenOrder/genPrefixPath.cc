#include "GenOrder.ih"

path GenOrder::prefPath(path const &fileInExFolder, size_t upto) const
{
  path prefix;
  auto filePathIterator = fileInExFolder.begin();
  for (size_t i = 0; i != upto; ++i)
  {
    prefix /= *filePathIterator;
    ++filePathIterator;
  }

  return prefix;
}
