#include "GenOrder.ih"
bool GenOrder::excluded(path const &toCheck) const
{
  path const prefix = prefPath(toCheck, SIZE_EX_FLDR_PREF);
  vp exclFromOrder = d_config.getExclFromOrder();
  return any_of(
    exclFromOrder.begin(), exclFromOrder.end(),
    [&](path const &toExcl)
    {
      return sameFile(prefix, toCheck, toExcl) || sameFolder(toCheck, toExcl);
    }
  );
}
