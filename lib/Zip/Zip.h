#ifndef ZIP_h_1681748133
#define ZIP_h_1681748133

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"

class Zip : public Command
{
  public:
    Zip(CommandRecipe recipe);
    void execute() override;
};

#endif
