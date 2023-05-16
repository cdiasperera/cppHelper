#include "Config.ih"
Config::Config()
  : d_notInOrder{getPathsToIgnoreForOrder()}
{
  // TODO: Probably could do this in init. list
  setPrios();
}
