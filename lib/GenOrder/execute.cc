#include "GenOrder.ih"
void GenOrder::execute()
{
  vector<path> exerciseFolders = getExerciseFolders();
  for (const auto &exerciseFolder: exerciseFolders)
  {
    vector<path> filesToAdd = getFilesToAdd(exerciseFolder);
    auto const folderGroups = reorderFilesToAdd(filesToAdd);
    writeToOrderFile(folderGroups);
  }

}
