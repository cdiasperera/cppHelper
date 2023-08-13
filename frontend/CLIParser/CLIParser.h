#ifndef CLIPARSER_h_1691750839
#define CLIPARSER_h_1691750839

#include "../../controller/Command/Command.h"

#include <vector>
#include <string>
#include <memory>

class CLIParser
{
  public:
    virtual ~CLIParser() = default;
    virtual std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> const &argv
    ) = 0;
};

#endif
