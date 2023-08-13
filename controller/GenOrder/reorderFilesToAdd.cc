#include "GenOrder.ih"

GenOrder::FolderGroups GenOrder::reorderFilesToAdd
(
  path const &exRoot, vp const &filesToAdd
) const
{
  // map files to folder they are under, i.e: prefix of path past
  // ex name
  unordered_map<string, vector<path>> folderGroups;
  for (auto const &file : filesToAdd)
    if (inExRootFolder(exRoot, file))
      // If under the root exercise folder, put into special group
      folderGroups[EX_ROOT_FLDR].push_back(file);
    else
    {
      // Get the relative path of file to exRoot and get the first
      // portion of that path, which is the subfolder name.
      auto folderInExRoot = *relative(file.string(), exRoot.string()).begin();
      folderGroups[folderInExRoot].push_back(file);
    }

  d_higherPriority("","");

  // Sort each group independently
  for (auto &folderGroup: folderGroups)
    sort(
      folderGroup.second.begin(), folderGroup.second.end(),
      [&](path const &p1, path const &p2)
      {
        return d_higherPriority(p1, p2);
      }
    );

  return folderGroups;
}
