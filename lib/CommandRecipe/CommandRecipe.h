#ifndef COMMANDRECIPE_h_1680680220
#define COMMANDRECIPE_h_1680680220

#include "../Flag/Flag.h"

#include <string>
#include <vector>

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
