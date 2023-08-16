#include "main.ih"

int main(int argc, char *argv[])
try
{
  vector<string> args{argv, argv + argc};

  unique_ptr<Frontend> frontend = make_unique<CLI>();
  auto cmd = frontend->readCommand(args.size(), args);
  cmd->execute();
}
catch (...)
{
  handleExceptions();
}