#ifndef GENFOLDER_h_1681332462
#define GENFOLDER_h_1681332462

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"
#include "../Config/Config.h"

// Command to generate folders
class GenFolder : public Command
{
  using ReplaceMap = std::unordered_map<std::string, std::string>;

  // (Relative) Argument positions in commands
  enum
  {
    TO_REPLACE_POS = 0,
    REPLACE_WITH_POS
  };


  char const REPLACE_FLAG = 'g';
  std::string const TO_REPLACE_SET = "<set-no>";
  std::string const TO_REPLACE_EX = "<ex-no>";

  Config d_config = Config::instance();

  // String to replace when copying template files
  ReplaceMap d_replaceMap;

  // Main arguments when constructing the folder structure
  std::string d_cpyInto;
  size_t d_set;
  size_t d_exStart;
  size_t d_exEnd;
  public:
    GenFolder(CommandRecipe recipe);
    void execute() override;
  private:
    void setMainArguments(CommandRecipe recipe);
};

#endif
