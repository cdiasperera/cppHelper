#include "Config.ih"
Config::Config()
  : d_ignoreForOrderPaths{getPathsToIgnoreForOrder()}
{
  setPrios();
}
