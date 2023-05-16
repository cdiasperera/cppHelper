#include "GenOrder.ih"
GenOrder::vp GenOrder::getFilesToAdd(path const &exerciseFolder) const
{
  vp filesToAdd;

  // Go through all files in an exercise folder and if it's not an excluded file
  // we add to it our list of files to add to the order.txt for this exercise
  recursive_directory_iterator exerciseIterator{exerciseFolder};
  for (auto const &entry : exerciseIterator)
    if (entry.is_regular_file() && not excluded(entry))
      filesToAdd.emplace_back(entry);


  return filesToAdd;
}
