#include "Config.ih"
void Config::createDefaultPrioFile() const
{
  ofstream prioFile{d_prioFile};

  prioFile << "$summary.txt\n"
    << "$grammar\n"
    << "$lexer\n"
    << ".h\n"
    << ".ih\n"
    << ".f\n"
    << ".hi\n"
    << ".cc\n"
    << ".cpp\n";
}
