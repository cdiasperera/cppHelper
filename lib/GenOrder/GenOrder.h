#ifndef GENORDER_h_1681748128
#define GENORDER_h_1681748128

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"
class GenOrder : public Command
{
  public:
    GenOrder(CommandRecipe recipe);
    void execute() override;
};

#endif
