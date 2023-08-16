#include "Config.ih"
vector<path> Config::initPathsToIgnoreForOrder() const
{
  if (not exists(d_ignoreLoc))
    createDefaultIgnoreFile();

  ifstream ignoreFile{d_ignoreLoc};
  vp pathsToIgnore;

  string line;
  while (getline(ignoreFile, line))
    pathsToIgnore.push_back(path(line));

  pathsToIgnore.push_back(path("order.txt"));
  return pathsToIgnore;
}
