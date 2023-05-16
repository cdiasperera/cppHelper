#include "GenOrder.ih"

GenOrder::vp GenOrder::getExerciseFolders() const
{
  vp exerciseFolders;

  // Iterate over base level of set to get exercise directories and make sure
  // that it is not excluded from generation.
  directory_iterator setIterator{d_setFolder};
  for (auto const &p : setIterator)
    if (p.is_directory() && not excludedExercise(p))
      exerciseFolders.emplace_back(p);


  return exerciseFolders;
}
