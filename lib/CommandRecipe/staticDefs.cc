#include "CommandRecipe.ih"
std::unordered_map<char, CommandRecipe::CommandType>
  CommandRecipe::s_chToCmdType =
{
  {'g', CommandType::GEN_FOLDER},
  {'o', CommandType::GEN_ORDER},
  {'z', CommandType::ZIP_SET}
};