#include "CommandRecipe.ih"
void CommandRecipe::setCmdType(char flag)
{
  d_cmdType = s_chToCmdType[flag];
}