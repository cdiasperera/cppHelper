#include "GenOrderParser.ih"

unique_ptr<Command> GenOrderParser::readCommand
(
  size_t argc, vector<string> const &argv
)
{
  vector<size_t> exsToIgnore;

  if (argv.size() > EXSTOIGNORE_LOC)
    exsToIgnore = stringToVectorByDelim<size_t>
    (
      argv[EXSTOIGNORE_LOC],
      ',',
      [](string const &str) {return stoul(str);}
    );

  auto prio = [](path const &p1, path const &p2)
  {
    // Can't use d_config as that would require making prio a lambda that
    // captures, and you cannot pass pointers to lambdas that capture.
    return Config{}.higherPriority(p1, p2);
  };

  return make_unique<GenOrder>
  (
    path(argv[SETLOC_LOC]), exsToIgnore,
    d_config.getPathsToIgnoreForOrder(), prio
  );
}
