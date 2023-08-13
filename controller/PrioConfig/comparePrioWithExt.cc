#include "PrioConfig.ih"
int PrioConfig::comparePrioWithExt
(
  string const &prioItem, path const &p1, path const &p2
) const
{
  auto const &prioExt = prioItem;
  bool p1HasSameExt = prioExt == p1.extension().string();
  bool p2HasSameExt = prioExt == p2.extension().string();

  if (p1HasSameExt && not p2HasSameExt)
    return -1;
  if (p2HasSameExt && not p1HasSameExt)
    return 1;

  return 0;
}
