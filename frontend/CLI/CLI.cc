#include "CLI.ih"

CLI::CLI()
{
  d_cmdParsers["-g"] = make_unique<GenFolderParser>();
  d_cmdParsers["-o"] = make_unique<GenOrderParser>();
  d_cmdParsers["-z"] = make_unique<ZipCommandParser>();
}
