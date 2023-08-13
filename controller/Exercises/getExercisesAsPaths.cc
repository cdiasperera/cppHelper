#include "Exercises.ih"
vector<path> Exercises::getExercisesAsPaths() const
{
  vector<path> paths;
  for (const auto &ex: d_exercises)
    paths.emplace_back(getExercisePath(ex));

  return paths;
}
