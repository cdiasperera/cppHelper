#include "GenOrder.ih"
GenOrder::vp GenOrder::getFilesToAdd(path const &exerciseFolder) const
{
  vp filesToAdd;

  recursive_directory_iterator exerciseIterator{exerciseFolder};
  for (auto const &entry : exerciseIterator)
    if (entry.is_regular_file() && not excluded(entry))
      filesToAdd.emplace_back(entry);


  return filesToAdd;
}
