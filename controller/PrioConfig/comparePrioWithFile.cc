#include "PrioConfig.ih"

int PrioConfig::comparePrioWithFile
(
  string const &prioName, path const &p1, path const &p2
) const
{
  if (p1.filename().string() == prioName)
    return -1;
  if (p2.filename().string() == prioName)
    return 1;
  return 0;
}
