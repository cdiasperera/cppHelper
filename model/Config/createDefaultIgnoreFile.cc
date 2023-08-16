#include "Config.ih"
void Config::createDefaultIgnoreFile() const
{
  if (not exists(d_ignoreLoc))
    ofstream metadataFile{d_ignoreLoc};
}
