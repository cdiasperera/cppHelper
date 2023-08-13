#ifndef GENFOLDER_h_1690878057
#define GENFOLDER_h_1690878057

#include "../Command/Command.h"
#include "../Exercises/Exercises.h"

#include <string>
#include <filesystem>
#include <unordered_map>

class GenFolder : public Command
{
  using path = std::filesystem::path;
  using ReplaceMap = std::unordered_map<std::string, std::string>;

  // Path config for command
  path d_metadataPath;
  path d_templateExPath;

  Exercises d_exercises;

  // Replace map
  ReplaceMap d_replaceMap;
  public:
    GenFolder
    (
      path const &setParent,
      size_t setNo, size_t exStr, size_t exEnd,
      path metadataPath, path templateExPath
    );
    ~GenFolder() override = default;
    void execute() override;

  private:
    void createFolderStructure() const;
    void replaceStrings(path const &setRoot);
};
#endif
