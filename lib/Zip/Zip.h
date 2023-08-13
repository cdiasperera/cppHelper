#ifndef ZIP_h_1691511175
#define ZIP_h_1691511175

#include <vector>
#include <filesystem>

class Zip
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  public:
    virtual void zip
    (
      path const &zipName, path const &zipFrom, vp const &toZip
    ) const = 0;
};

#endif
