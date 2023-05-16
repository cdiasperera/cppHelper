#include "GenOrder.ih"

namespace
{
  // The format we write each file to the output as.
  void writeFile(ostream &out, path const &file);
}

void GenOrder::writeToOrderFile(FolderGroups const &folderGroups) const
{
  // Get the location the order file. Its prefix is based on the prefix of any
  // of the files in our folder groups.
  auto aFile = folderGroups.at(EX_ROOT_FLDR).front();
  auto orderFileLoc = prefPath(aFile, SIZE_EX_FLDR_PREF);
  ofstream orderFile{orderFileLoc/"order.txt"};

  // Write the root folder first, so the summary goes at the top
  for (auto const &file: folderGroups.at(EX_ROOT_FLDR))
    writeFile(orderFile, file);
  orderFile << '\n';              // Separation between groups

  // Write the rest of the groups afterwards
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
