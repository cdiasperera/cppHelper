#ifndef COMMANDRECIPE_h_1680680220
#define COMMANDRECIPE_h_1680680220

#include "../Flag/Flag.h"

#include <string>
#include <vector>

// A POD for a command, consisting of the main command type, flags and the
// main arguments.
struct CommandRecipe
{
  enum class CommandType
  {
      GEN_FOLDER
  };

  CommandType cmdType;
  std::vector<Flag> flags;
  std::vector<std::string> args;
};

#endif
