#include <utility>

#include "GenOrder.ih"

GenOrder::GenOrder
(
  path const &setLoc, std::vector<size_t> const &exsToIgnore, vp pathsToIgnore,
  function<PrioCmpFunc> higherPriority
)
  : d_exercises{setLoc, exsToIgnore},
    d_pathsToIgnore{std::move(pathsToIgnore)}
{
  d_higherPriority = std::move(higherPriority);
}
