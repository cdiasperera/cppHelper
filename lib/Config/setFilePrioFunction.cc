#include "Config.ih"
void Config::setPrios()
{
  if (not exists(d_prioFile))
    createDefaultPrioFile();

  ifstream prioFile{d_prioFile};

  copy(
    istream_iterator<string>{prioFile}, istream_iterator<string>{},
    back_inserter(d_prios)
  );
}
