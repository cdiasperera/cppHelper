#include <utility>

#include "ZipCommand.ih"
ZipCommand::ZipCommand
(
  path zipLoc,
  path const &setLoc, std::vector<size_t> const &exsToIgnore
)
  : d_zipLoc{std::move(zipLoc)},
    d_exercises{setLoc, exsToIgnore}
{}
