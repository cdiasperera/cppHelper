#ifndef COMMANDRECIPE_h_1680680220
#define COMMANDRECIPE_h_1680680220

#include "../Flag/Flag.h"

#include <string>
#include <vector>
#include <unordered_map>

// A POD for a command, consisting of the main command type, flags and the
// main arguments.
struct CommandRecipe
{
  enum class CommandType
  {
      GEN_FOLDER,
      GEN_ORDER,
      ZIP_SET
  };

  std::vector<Flag> d_flags;
  std::vector<std::string> d_args;

  void setCmdType(char flag);
  private:
    static std::unordered_map<char, CommandType> s_chToCmdType;
    CommandType d_cmdType;
};

#endif
