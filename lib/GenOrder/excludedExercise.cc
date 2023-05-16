#include "GenOrder.ih"
bool GenOrder::excludedExercise(path const &folder) const
{
              // If folder is excluded, then it will be in d_excludeList and
              // the find() function will return a non end() iterator.
  return
    find(d_exExclList.begin(), d_exExclList.end(), folder.filename())
    != d_exExclList.end();
}
