#include "GenFolder.ih"
GenFolder::GenFolder(CommandRecipe recipe)
{
  setMainArguments();

  d_replaceMap.insert(
    {TO_REPLACE_SET, std::to_string(d_set)}
  );
  d_replaceMap.insert(
    {TO_REPLACE_EX, std::to_string(d_exStart)}
  );

  for (const auto &flag: recipe.flags)
    if (flag.flag == REPLACE_FLAG)
      d_replaceMap.insert(
        {flag.args[TO_REPLACE_POS], flag.args[REPLACE_WITH_POS]}
      );
}
