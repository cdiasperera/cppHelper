#ifndef ZIPCOMMANDPARSER_h_1691823156
#define ZIPCOMMANDPARSER_h_1691823156

#include "../CLIParser/CLIParser.h"
#include "../../controller/ZipCommand/ZipCommand.h"
#include "../../model/Config/Config.h"

class ZipCommandParser : public CLIParser
{
    enum
    {
      ZIPLOC_LOC,
      SETLOC_LOC,
      EXSTOIGNORE_LOC
    };

  public:
    ZipCommandParser() = default;
    ~ZipCommandParser() override = default;
    std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> const &argv
    ) override;
};
#endif
