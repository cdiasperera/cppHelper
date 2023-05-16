#include "GenOrder.ih"

GenOrder::GenOrder(CommandRecipe recipe)
  : d_setFolder(recipe.d_args[SET_FLDR_ARG_POS])
{
  // Add args to d_exclList, except for single digit exercises, but it in double
  // digit format
  auto args = recipe.d_args;
  for (auto it = args.begin() + IGNORE_ARG_START; it != args.end(); ++it)
  {
    string toInsert = *it;
    size_t exNo = stoul(toInsert);

    if (exNo <= 9 && toInsert.size() < 2)
      toInsert.insert(0, "0");

    d_exExclList.push_back(toInsert);
  }
}
