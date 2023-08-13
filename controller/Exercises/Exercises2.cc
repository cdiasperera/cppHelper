#include <utility>

#include "Exercises.ih"
Exercises::Exercises
(
  path setLoc, vector<size_t> const &excl, size_t exStr, size_t exEnd
)
  : d_setLoc{std::move(setLoc)}
{
  for (size_t ex = exStr; ex <= exEnd; ex++)
    if (not contains(excl, ex))
      d_exercises.emplace_back(ex);
}
