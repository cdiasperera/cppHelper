#include "Config.ih"

int Config::comparePrioWith(
  string const &prioItem, path const &p1, path const &p2
) const
{
  auto prioName = fileName(prioItem);

                      // Same name (and therefore extension) so same priority
  if (p1.filename().string() == p2.filename().string())
    return 0;

                      // If prioItem is a file, check if p1,p2 have the same
                      // name. If one does, it must have the higher priority,
                      // as the other must have a different name
  if (isFile(prioItem))
  {
    if (p1.filename().string() == prioName)
      return -1;
    if (p2.filename().string() == prioName)
      return 1;
    return 0;
  }

  // prioItem is an extension
  auto const &prioExt = prioItem;
  bool p1HasSameExt = prioExt == p1.extension().string();
  bool p2HasSameExt = prioExt == p2.extension().string();

  if (p1HasSameExt && not p2HasSameExt)
    return -1;
  if (p2HasSameExt && not p1HasSameExt)
    return 1;

  // Different extensions for both, both are totally different from the prioItem
  return 0;


}
