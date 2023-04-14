#include "GenFolder.ih"
void GenFolder::setMainArguments(CommandRecipe recipe)
{
  auto args = recipe.args;
  if (noFolderInArgs(recipe))
    d_cpyInto = ".";
  else
  {
    d_cpyInto = args[0];
    args.
  }
}
