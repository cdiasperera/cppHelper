#include "LinuxZip.ih"
void LinuxZip::zip
(
  path const &zipLoc, path const &zipFrom, vp const &toZip
) const
{
  string cdToZipFromCmd = "cd " + zipFrom.string();

  string zipCommand = "zip " + relative(zipLoc, zipFrom).string() + " ";
  for (const auto &item: toZip)
    zipCommand += (item.string() + " ");

  string command = cdToZipFromCmd + " && " + zipCommand;

  system(command.c_str());
}
