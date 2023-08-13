#include "GenOrder.ih"

namespace
{
  // The format we write each file to the output as.
  void writePath(ostream &out, path const &file, path const &relTo);
  void writePaths(ostream &out, vector<path> const &paths, path const &relTo);
}

void GenOrder::writeToOrderFile
(
  path const &exRoot, FolderGroups const &folderGroups
) const
{
  ofstream orderFile{exRoot/"order.txt"};

  // Write root group, and then other groups
  writePaths(orderFile, folderGroups.at(EX_ROOT_FLDR), exRoot);
  for (auto const &folderGroup : folderGroups)
    if (folderGroup.first != EX_ROOT_FLDR)
      writePaths(orderFile, folderGroup.second, exRoot);
}

namespace
{
  void writePath(ostream &out, path const &file, path const &relTo)
  {
    out << relative(file, relTo).string() << '\n';
  }

  void writePaths(ostream &out, vector<path> const &paths, path const &relTo)
  {
    for (auto const &path : paths)
      writePath(out, path, relTo);
    out << '\n';

  }
}
