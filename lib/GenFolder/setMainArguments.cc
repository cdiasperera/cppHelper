#include "GenFolder.ih"
void GenFolder::setMainArguments(CommandRecipe const &recipe)
{
  auto args = recipe.d_args;
  if (noFolderInArgs(args))
    d_cpyInto = ".";
  else
  {
    d_cpyInto = args.front();
    args.erase(args.begin());
  }

  d_set = stoul(args[SET_ARG_POS]);
  d_exStart = stoul(args[EXSTART_ARG_POS]);
  d_exEnd = stoul(args[EXEND_ARG_POS]);
}
