#include "PrioConfig.ih"

int PrioConfig::comparePrioWith(
  string const &prioItem, path const &p1, path const &p2
) const
{
  auto prioName = fileName(prioItem);

  // Same name (and therefore extension) so same priority
  if (p1.filename().string() == p2.filename().string())
    return 0;

  if (isFile(prioItem))
    return comparePrioWithFile(prioName, p1, p2);

  // prioItem is an extension
  return comparePrioWithExt(prioItem, p1, p2);
}
