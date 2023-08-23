#include "ZipCommandParser.ih"

unique_ptr<Command> ZipCommandParser::readCommand
(
  size_t argc, vector<string> const &argv
)
{
  vector<size_t> exsToIgnore;
  if (argv.size() > EXSTOIGNORE_LOC && argv[EXSTOIGNORE_LOC] != "none")
    exsToIgnore = stringToVectorByDelim<size_t>
    (
      argv[EXSTOIGNORE_LOC],
      ',',
      [](string const &str) {return stoul(str);}
    );

  return make_unique<ZipCommand>
  (
    argv[ZIPLOC_LOC], argv[SETLOC_LOC], exsToIgnore
  );
}
