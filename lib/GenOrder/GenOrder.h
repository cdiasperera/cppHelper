#ifndef GENORDER_h_1681748128
#define GENORDER_h_1681748128

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"

#include "../Config/Config.h"
class GenOrder : public Command
{
  enum
  {
    SET_FOLDER_ARG_POS = 0
  };

  Config const &d_config = Config::instance();
  std::string const d_setFolder;

  public:
    GenOrder(CommandRecipe recipe);
    void execute() override;
};

#endif
