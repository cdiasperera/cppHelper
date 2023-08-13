#include "GenFolder.ih"
void GenFolder::execute()
{
  // Check if folder already exists
  path setRoot = d_exercises.getSetFolder();
  if (exists(setRoot))
  {
    cerr << "Folder already exists";
    return;
  }

  createFolderStructure();
  replaceStrings(setRoot);
}

