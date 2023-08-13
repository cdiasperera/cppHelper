#include "PrioConfig.ih"
                  // Returns true iff p1 has higher prio than p2
bool PrioConfig::higherPriority(path const &p1, path const &p2) const
{
  // Essentially, we find the highest priority element that is relevant (i.e:
  // compRes != 0) and we report the result of comparing against that element.

  int compRes;
  for (const auto &prioItem: d_prioList)
  {
    compRes = comparePrioWith(prioItem, p1, p2);
    if (compRes != 0)
      break;
  }

                // compRes < 0 => p1 has higher prio
                // compRes > 0 => p2 has higher prio
                // compRes == 0 => same prio, so we should return false
  return compRes < 0;
}
