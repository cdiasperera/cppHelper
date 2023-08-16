#include "Config.ih"
void Config::createDefaultIgnoreFile() const
{
  if (not exists(d_metadataPath))
    ofstream metadataFile{d_metadataPath};
}
