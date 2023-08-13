#include "CLI.ih"
unique_ptr<Command> CLI::readCommand(size_t argc, vector<string> argv)
{
  string cmd = argv[CMD_LOC];

  vector<string> cmdArgs{argv.begin() + CMD_LOC + 1, argv.end()};

  auto &parser = d_cmdParsers[cmd];

  return parser->readCommand
  (
    cmdArgs.size(), cmdArgs
  );
}
