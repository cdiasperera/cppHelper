#include "GenOrder.ih"
void GenOrder::execute()
{
  auto exercises = d_exercises.getExercisesAsPaths();
  for (const auto &exRoot: exercises)
  {
    vector<path> filesToAdd = allFilesIn
      (
        exRoot,
        [&](path const &p)
        {
           return this->excludedPath(exRoot, p);
        }
      );
    auto const folderGroups = reorderFilesToAdd(exRoot, filesToAdd);
    writeToOrderFile(exRoot, folderGroups);
  }

}
