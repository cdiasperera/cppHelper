#include "Config.ih"
vector<path> Config::getPathsToIgnoreForOrder() const
{
  ifstream ignoreFile{d_ignoreForOrderFile};
  vp pathsToIgnore;

  string line;
  while (getline(ignoreFile, line))
    pathsToIgnore.emplace_back(line);

  pathsToIgnore.emplace_back("order.txt");
  return pathsToIgnore;
}
