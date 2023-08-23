#include "AslZip.ih"
void AslZip::zip
(
  path const &zipLoc, path const &zipFrom, vp const &toZip
) const
{
  ZipFile zip(zipLoc.filename().c_str());

  for (const auto &item: toZip)
  {
    string dirInZip = item.parent_path().string() + "/";
    zip.add(dirInZip.c_str(), File((zipFrom/item).c_str()));
  }
}
