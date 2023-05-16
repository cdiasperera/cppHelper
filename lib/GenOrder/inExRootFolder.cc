#include "GenOrder.ih"
bool GenOrder::inExRootFolder(path const &file) const
{
  size_t dirDepth = 0;
  for(auto it = file.begin(); it != file.end(); ++it, ++dirDepth)
    if (dirDepth > SIZE_EX_FLDR_PREF)
      return false;

  return true;
}
