#include "GenOrder.ih"

namespace
{
  void writeFile(ostream &out, path const &file);
}

void GenOrder::writeToOrderFile(FolderGroups const &folderGroups) const
{
  // Get the location the order file should be in from any file in the groups
  auto aFile = folderGroups.at(EX_ROOT_FLDR).front();
  auto orderFileLoc = prefPath(aFile, SIZE_EX_FLDR_PREF);
  ofstream orderFile{orderFileLoc/"order.txt"};

  for (auto const &file: folderGroups.at(EX_ROOT_FLDR))
    writeFile(orderFile, file);
  orderFile << '\n';              // Separation between groups

  for (auto const &folderGroup : folderGroups)
    if (folderGroup.first != EX_ROOT_FLDR)
    {
      for (auto const &file: folderGroup.second)
        writeFile(orderFile, file);
      orderFile << '\n';          // Separation between groups
    }
}

namespace
{
  void writeFile(ostream &out, path const &file)
  {
    out << file.string() << '\n';
  }
}
