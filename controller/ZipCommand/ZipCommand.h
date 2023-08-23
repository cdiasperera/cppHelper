#ifndef ZIP_h_1691396908
#define ZIP_h_1691396908

#include "../Command/Command.h"
#include "../Exercises/Exercises.h"
#include "../../lib/AslZip/AslZip.h"

class ZipCommand : public Command
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;

  path d_zipLoc;

  Exercises d_exercises;
  AslZip d_zipper;
  public:
    ZipCommand
    (
      path zipLoc,
      path const &setLoc, std::vector<size_t> const &exsToIgnore
    );
    ~ZipCommand() override = default;
    void execute() override;

  private:
    void addPathsFromExercise
    (
      path const &setLoc, path const &ex, vp &filesToAdd
    );
    bool validExerciseSubmission(path const &ex);
};

#endif
