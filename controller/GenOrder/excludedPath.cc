#include "GenOrder.ih"
bool GenOrder::excludedPath(path const &exRoot, path const &toCheck) const
{
  return any_of(
    d_pathsToIgnore.begin(), d_pathsToIgnore.end(),
    [&](path const &toExcl)
    {
      return sameFile(exRoot, toCheck, toExcl)
             || inSameFolder(exRoot, toCheck, toExcl);
    }
  );
}
