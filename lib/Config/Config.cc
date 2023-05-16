#include "Config.ih"
Config::Config()
  : d_exclFromOrder{getPathsToIgnoreForOrder()}
{
  // TODO: Probably could do this in init. list
  setPrios();
}
