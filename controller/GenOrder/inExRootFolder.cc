#include "GenOrder.ih"
bool GenOrder::inExRootFolder(path const &exRoot, path const &file)
{
  return file.parent_path() == exRoot;
}
