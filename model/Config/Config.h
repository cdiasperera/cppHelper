#ifndef CONFIG_h_1680618520
#define CONFIG_h_1680618520

#include <filesystem>
#include <vector>
#include <unordered_map>
#include "../PrioConfig/PrioConfig.h"

// TODO: Probably should make this a singleton.

class Config
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  using vs = std::vector<std::string>;

  // The following are constants, but making them const deletes their copy
  // constructor, which we need.

  // Parent folder of configuration settings
  path d_configFolder = path(getenv("HOME"))/".cpphelper";
  // Location of metadata file
  path d_metadataPath = d_configFolder/"metadata.txt";
  // Location of exercise template folder
  path d_exerciseTemplateFolder = d_configFolder/"exercise";
  // Location of files to not include in order.txt
  path d_ignoreLoc = d_configFolder / "ignore.txt";
  // (Relative) Paths to ignore, when generating order.txt
  vp d_pathsToIgnoreForOrder;

  // Helper object for managing priority files
  PrioConfig d_prioConfig = PrioConfig{d_configFolder};

  public:
    Config();
    // Get the path to the folder which contains the exercise template to copy
    path const &getTemplateFolderPath() const;

    // Get the path to the metadata file that must be in each set
    path const &getMetadataPath() const;

    // Get the files that should be excluded from the order.txt
    vp const &getPathsToIgnoreForOrder() const;

    // Returns true if p1 has higher priority than p2 in the order.txt
    bool higherPriority(path const &p1, path const &p2) const;
  private:
    // Read paths to ignore when generating order.txt
    vp initPathsToIgnoreForOrder() const;

    void createDefaultMetadataFile() const;
    void createDefaultIgnoreFile() const;
    void createDefaultTemplateExercise() const;
};
inline Config::path const &Config::getTemplateFolderPath() const
{
  return d_exerciseTemplateFolder;
}

inline Config::path const &Config::getMetadataPath() const
{
  return d_metadataPath;
}

inline Config::vp const &Config::getPathsToIgnoreForOrder() const
{
  return d_pathsToIgnoreForOrder;
}

inline bool Config::higherPriority(const path &p1, const path &p2) const
{
  return d_prioConfig.higherPriority(p1, p2);
}

#endif
