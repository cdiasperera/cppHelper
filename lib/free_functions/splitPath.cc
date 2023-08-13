#include "free_functions.ih"

pair<path,std::filesystem::path> splitPath
(
  path const &pth, size_t splitAt
)
{
  path prefix;
  path suffix;

  // Go through each path element (within 'upto' limit), and attach it to
  // the prefix.
  auto filePathIterator = pth.begin();
  for (size_t i = 0; i != splitAt; ++i, ++filePathIterator)
    prefix /= *filePathIterator;

  while (filePathIterator != pth.end())
  {
    suffix /= *filePathIterator;
    ++filePathIterator;
  }

  return {prefix, suffix};
}
