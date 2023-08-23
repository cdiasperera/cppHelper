#ifndef LINUXZIP_h_1691511255
#define LINUXZIP_h_1691511255

#include "../Zip/Zip.h"

class AslZip : public Zip
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;

  public:
    AslZip();
    ~AslZip() = default;
    void zip
    (
      path const &zipLoc, path const &zipFrom, const vp &toZip
    ) const override;
};

#endif
