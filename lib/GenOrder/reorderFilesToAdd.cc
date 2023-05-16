#include "GenOrder.ih"

GenOrder::FolderGroups GenOrder::reorderFilesToAdd(vp const &filesToAdd) const
{
  // map files to folder they are under, i.e: prefix of path past
  // ex name
  unordered_map<string, vector<path>> folderGroups;
  for (auto const &file : filesToAdd)
    if (inExRootFolder(file))
      // If under the root exercise folder, put into special group
      folderGroups[EX_ROOT_FLDR].push_back(file);
    else
      folderGroups[prefPath(file, SIZE_EX_FLDR_PREF + 1)].push_back(file);

  // Sort each group independently
  for (auto &folderGroup: folderGroups)
  {
    sort(
      folderGroup.second.begin(), folderGroup.second.end(),
      [&](path const &p1, path const &p2)
      {
        return d_config.higherPriority(p1, p2);
      }
    );
  }

  return folderGroups;
}
