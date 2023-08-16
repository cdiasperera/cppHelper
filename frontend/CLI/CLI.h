#ifndef CLI_h_1691573566
#define CLI_h_1691573566

#include "../Frontend/Frontend.h"
#include "../../controller/Command/Command.h"
#include "../CLIParser/CLIParser.h"
#include "../FrontendException/FrontendException.h"

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

class CLI : public Frontend
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
    ~CLI() = default;

    std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> argv
    ) override;

  private:
    void handleException(std::exception const &exception) const;
    std::string usage() const;
};

#endif
