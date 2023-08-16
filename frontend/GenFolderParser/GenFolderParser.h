#ifndef GENFOLDERPARSER_h_1691751614
#define GENFOLDERPARSER_h_1691751614

#include "../CLIParser/CLIParser.h"
#include "../../controller/GenFolder/GenFolder.h"
#include "../../model/Config/Config.h"

class GenFolderParser : public CLIParser
{
  enum
  {
    SETLOC_LOC,
    SETNO_LOC,
    EXSTR_LOC,
    EXEND_LOC
  };

  Config d_config;

  public:
    GenFolderParser() = default;
    ~GenFolderParser() override = default;
    std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> const &argv
    ) override;
};

#endif
