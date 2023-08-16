#include "CLI.ih"

unique_ptr<Command> CLI::readCommand(size_t argc, vector<string> argv)
try {
  string cmd = argv.at(CMD_LOC);
  vector<string> cmdArgs{argv.begin() + CMD_LOC + 1, argv.end()};

  auto &parser = d_cmdParsers.at(cmd);

  return parser->readCommand(cmdArgs.size(), cmdArgs);
} catch (out_of_range &exception)
{
  auto actualExp = FrontendException("Need a valid command as the first arg");
  handleException(actualExp);
  throw FrontendException(actualExp);
} catch (...)
{
  auto excep = invalid_argument("Error with arguments");
  handleException(excep);
  throw invalid_argument(excep);
}