#include "PrioConfig.ih"
PrioConfig::PrioConfig(path const &configFolder)
  : d_prioFile{configFolder/d_prioFileName}
{
  initPrioList();
}
