#ifndef CONFIG_h_1680618520
#define CONFIG_h_1680618520

#include <filesystem>
#include <vector>
#include <unordered_map>

// Singleton object containing configuration for program, obtained from a
// configuration file.
class Config
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  using vs = std::vector<std::string>;

  enum
  {
    FILE_NAME_PREFIX = '$'
  };
                          // Singleton members
  static bool s_initd;
  static Config s_singleton;

            // Parent folder of configuration settings
  path d_configFolder = path(getenv("HOME"))/".cpphelper";

            // Location of configuration settings
  path d_exerciseTemplateFolder = d_configFolder/"exercise";
  path d_ignoreForOrderFile = d_configFolder/"ignore.txt";
  path d_prioFile = d_configFolder / "prio.txt";

  vp d_ignoreForOrderPaths;
  vs d_prios;

  public:
    path const &getTemplateFolderPath() const;
    vp const &getIgnoreForOrderPaths() const;
    static Config &instance();
    bool orderFilePriority(path const &p1, path const &p2) const;
  private:
    Config();
    vp getPathsToIgnoreForOrder() const;
    void setPrios();
    void createDefaultPrioFile() const;
    int comparePrioWith(
      std::string const &prioItem, path const &p1, path const &p2
    ) const;

    bool isFile(std::string const &prioFileLine) const;
    std::string fileName(std::string const &prioFileLine) const;

};
inline Config::path const &Config::getTemplateFolderPath() const
{
  return d_exerciseTemplateFolder;
}

inline Config::vp const &Config::getIgnoreForOrderPaths() const
{
  return d_ignoreForOrderPaths;
}

inline bool Config::isFile(std::string const &prioFileLine) const
{
  if (prioFileLine.front() == FILE_NAME_PREFIX)
    return true;
  return false;
}

inline std::string Config::fileName(std::string const &prioFileLine) const
{
            // Just remove the file name prefix
  return prioFileLine.substr(1);
}

#endif
