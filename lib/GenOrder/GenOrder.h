#ifndef GENORDER_h_1681748128
#define GENORDER_h_1681748128

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"

#include "../Config/Config.h"

#include <unordered_map>
class GenOrder : public Command
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  using vs = std::vector<std::string>;
  using FolderGroups = std::unordered_map<std::string, vp>;

  enum
  {
    SET_FOLDER_ARG_POS = 0,
    IGNORE_FOLDERS_ARG_STAR = 1,
    SIZE_EX_FLDR_PREF = 3
  };

  std::string const EX_ROOT_FLDR = "root";

  Config const &d_config = Config::instance();
  path const d_setFolder;

  vs d_exExclList;

  public:
    GenOrder(CommandRecipe recipe);
    void execute() override;

  private:
    vp getExerciseFolders() const;
    bool excludedExercise(path const &folder) const;

    vp getFilesToAdd(path const &exerciseFolder) const;
    bool excluded(path const &toCheck) const;
    path prefPath(path const &fileInExFolder, size_t upto) const;
    bool inExRootFolder(path const &file) const;
    bool sameFile(
      path const &exPrefix, path const &toCheck, path const &toExclude
    ) const;
    bool sameFolder(path const &toCheck, path const &toExclude) const;

    FolderGroups reorderFilesToAdd(vp const &filesToAdd) const;
    void writeToOrderFile(FolderGroups const &folderGroups) const;
};

#endif
