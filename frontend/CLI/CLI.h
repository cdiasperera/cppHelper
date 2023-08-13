#ifndef CLI_h_1691573566
#define CLI_h_1691573566

#include "../../controller/Command/Command.h"
#include "../CLIParser/CLIParser.h"

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

class CLI
{
  using CmdParserMap = std::unordered_map
  <
    std::string, std::unique_ptr<CLIParser>
  >;

  enum
  {
    CMD_LOC = 1
  };

  CmdParserMap d_cmdParsers;

  public:
    CLI();

    std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> argv
    );
};

#endif
