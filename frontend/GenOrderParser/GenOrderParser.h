#ifndef GENORDERPARSER_h_1691823150
#define GENORDERPARSER_h_1691823150

#include "../CLIParser/CLIParser.h"
#include "../../controller/GenOrder/GenOrder.h"
#include "../../model/Config/Config.h"

class GenOrderParser : public CLIParser
{
    enum
    {
      SETLOC_LOC,
      EXSTOIGNORE_LOC
    };

    Config const d_config;

  public:
    GenOrderParser() = default;
    ~GenOrderParser() override = default;
    std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> const &argv
    ) override;
};

#endif
