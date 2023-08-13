#include "GenFolder.ih"
void GenFolder::replaceStrings(path const &setRoot)
{
  // Replace strings, making sure to set ex-no to the right folder name
  for (auto const &ex: d_exercises.getExercisesAsNumbers())
  {
    string exName = withLeadingZeros(2, ex);
    d_replaceMap["<ex-no>"] = to_string(ex);
    replaceStringsInFolder(setRoot/exName, d_replaceMap);
  }

  // Reset ex-no to "unknown"
  d_replaceMap["<ex-no>"] = "";
}
