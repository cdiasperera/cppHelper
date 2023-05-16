#include "Config.ih"
                  // Returns true iff p1 has higher prio than p2
bool Config::orderFilePriority(path const &p1, path const &p2) const
{
  int compRes;
  for (const auto &prioItem: d_prios)
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
