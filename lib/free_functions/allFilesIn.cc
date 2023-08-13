#include "free_functions.ih"
vector<path> allFilesIn
(
  path const &folder, function<bool (path)> const &excluded
)
{
  vector<path> filesToAdd;

  // Go through all files in an exercise folder and if it's not an excluded file
  // we add to it our list of files to add to the order.txt for this exercise
  recursive_directory_iterator folderIterator{folder};
  for (auto const &entry : folderIterator)
    if (entry.is_regular_file() && not excluded(entry))
      filesToAdd.emplace_back(entry);


  return filesToAdd;
}
