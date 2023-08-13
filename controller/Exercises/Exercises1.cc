#include "Exercises.ih"
Exercises::Exercises(path const &setLoc, vector<size_t> const &excl)
  : d_setLoc{setLoc}
{

  for (auto const &p : directory_iterator{setLoc})
    if (p.is_directory())
    {
      size_t ex = stoul(p.path().filename());
      if (not contains(excl, ex))
        d_exercises.emplace_back(ex);
    }
}
