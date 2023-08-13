#include "GenFolderParser.ih"

unique_ptr<Command> GenFolderParser::readCommand
(
  size_t argc, vector<string> const &argv
)
{
  return make_unique<GenFolder>
  (
      path(argv[SETLOC_LOC]), stoul(argv[SETNO_LOC]),
      stoul(argv[EXSTR_LOC]), stoul(argv[EXEND_LOC]),
      d_config.getMetadataPath(), d_config.getTemplateFolderPath()
  );
}
