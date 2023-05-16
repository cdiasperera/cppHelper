#include "GenOrder.ih"

GenOrder::GenOrder(CommandRecipe recipe)
  : d_setFolder(recipe.d_args[SET_FOLDER_ARG_POS]),
    d_exExclList
    {
      recipe.d_args.begin() + IGNORE_FOLDERS_ARG_STAR,
      recipe.d_args.end()
    }
{}
