#include "GenFolder.ih"
#include "GenFolder.h"

#include <utility>

GenFolder::GenFolder
(
  path const &setParent,
  size_t setNo, size_t exStr, size_t exEnd,
  path metadataPath, path templateExPath
)
  : d_metadataPath{std::move(metadataPath)},
    d_templateExPath{std::move(templateExPath)},
    d_exercises
    {
      setParent/("set"+to_string(setNo)), vector<size_t>{}, exStr, exEnd
    }
{
  d_replaceMap["<set-no>"] = to_string(setNo);
  d_replaceMap["<ex-no>"] = "";
}