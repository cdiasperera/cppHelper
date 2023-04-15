#include "GenFolder.ih"
GenFolder::GenFolder(CommandRecipe recipe)
{
  setMainArguments(recipe);

  d_replaceMap.insert(
    {TO_REPLACE_SET, std::to_string(d_set)}
  );
  d_replaceMap.insert(
    {TO_REPLACE_EX, std::to_string(d_exStart)}
  );

  for (const auto &flag: recipe.d_flags)
    if (flag.d_flag == REPLACE_FLAG)
      d_replaceMap.insert(
        {flag.d_args[TO_REPLACE_POS], flag.d_args[REPLACE_WITH_POS]}
      );
}
