#include "GenFolder.ih"
void GenFolder::createFolderStructure() const
{
  auto setFolder = d_exercises.getSetFolder();

  // Create Folder
  create_directories(setFolder);
  // Copy Metadata
  copy(d_metadataPath, setFolder);

  // Create Folder Structure
  for (const auto &ex: d_exercises.getExercisesAsPaths())
  {
    create_directory(ex);
    copy(d_templateExPath, ex, copy_options::recursive);
  }
}
