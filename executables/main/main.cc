#include "main.ih"

#include "../../controller/GenOrder/GenOrder.h"

int main(int argc, char *argv[])
{
  vector<string> args{argv, argv + argc};

  auto cmd = CLI{}.readCommand(args.size(), args);
  cmd->execute();
}
