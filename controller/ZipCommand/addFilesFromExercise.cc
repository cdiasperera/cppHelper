#include "ZipCommand.ih"
void ZipCommand::addPathsFromExercise
(
  path const &setLoc, path const &ex, vp &filesToAdd
)
{
  path orderTxt = ex / "order.txt";

  if (not exists(orderTxt))
  {
    cerr << "WARNING: No order.txt in " << ex.string() << '\n';
    return;
  }
  ifstream orderStream = ifstream{orderTxt};
  vp pathsInOrder;

  copy
  (
    istream_iterator<string>{orderStream}, istream_iterator<string>{},
    back_inserter(pathsInOrder)
  );

  for (const auto &path: pathsInOrder)
    filesToAdd.push_back(relative(ex, setLoc) / path);
}
