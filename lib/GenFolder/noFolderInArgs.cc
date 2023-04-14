#include "GenFolder.ih"
bool GenFolder::noFolderInArgs(vector<string> const &args) const
{
  if (args.size() == NO_FOLDER_IN_ARGS_LEN)
    return true;
  return false;
}
