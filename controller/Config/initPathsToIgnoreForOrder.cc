#include "Config.ih"
vector<path> Config::initPathsToIgnoreForOrder() const
{
  ifstream ignoreFile{d_ignoreLoc};
  vp pathsToIgnore;

  string line;
  while (getline(ignoreFile, line))
    pathsToIgnore.emplace_back(line);

  pathsToIgnore.emplace_back("order.txt");
  return pathsToIgnore;
}
