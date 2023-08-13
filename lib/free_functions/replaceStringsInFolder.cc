#include "free_functions.ih"

void replaceStringsInFolder(path const &folder, ReplaceMap const &replaceMap)
{
  for (auto const &entry : recursive_directory_iterator{folder})
    if (entry.is_regular_file() and not entry.is_symlink())
      replaceStringsInFile(entry, replaceMap);
}