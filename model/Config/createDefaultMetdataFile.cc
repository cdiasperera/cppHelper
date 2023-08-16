#include "Config.ih"
void Config::createDefaultMetadataFile() const
{
  if (not exists(d_metadataPath))
    ofstream metadataFile{d_metadataPath};
}
