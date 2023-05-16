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

            // Location of exercise template folder
  path d_exerciseTemplateFolder = d_configFolder/"exercise";
            // Location of files to not include in order.txt
  path d_ignoreLoc = d_configFolder / "ignore.txt";
            // File of extension / filename priorities for order.txt
  path d_prioFile = d_configFolder / "prio.txt";

            // (Relative) Paths to ignore, when generating order.txt
  vp d_exclFromOrder;
            // Extension / filename priorities for order.txt
            // Filenames are prefixed by FILE_NAME_PREFIX to differentiate it
            // from extensions (as some files might start with a '.')
  vs d_prios;

  public:
    // Get the singleton instance of the Config object
    static Config &instance();

    // Get the path to the folder which contains the exercise template to copy
    path const &getTemplateFolderPath() const;

    // Get the files that should be excluded from the order.txt
    vp const &getExclFromOrder() const;
    // Returns true if p1 has higher priority than p2 in the order.txt
    bool higherPriority(path const &p1, path const &p2) const;
  private:
    Config();

    // Read paths to ignore when generating order.txt
    vp getPathsToIgnoreForOrder() const;
    // Set filename / extension priorities
    void setPrios();
    // Create default priority file
    void createDefaultPrioFile() const;
    // Return -1 if p1 has higher priority to p2 wrt to prioItem
    //         1 if p2 has higher priority
    //         0 if same priority
    // By WRT:  If prioItem is a filename, the path with higher priority is that
    //          with the same name. If same name, same prio.
    //          If prioItem is an extension, the path with higher priority is
    //          that with the extension that is the same as prioItem. If same
    //          extension, same prio.
    int comparePrioWith(
      std::string const &prioItem, path const &p1, path const &p2
    ) const;

    //  Whether the line (from the priority file) denotes a file, based on our
    // convention.
    bool isFile(std::string const &prioFileLine) const;
    // The filename of a line (from the priority file).
    std::string fileName(std::string const &prioFileLine) const;

};
inline Config::path const &Config::getTemplateFolderPath() const
{
  return d_exerciseTemplateFolder;
}

inline Config::vp const &Config::getExclFromOrder() const
{
  return d_exclFromOrder;
}

inline bool Config::isFile(std::string const &prioFileLine) const
{
  return prioFileLine.front() == FILE_NAME_PREFIX;
}

inline std::string Config::fileName(std::string const &prioFileLine) const
{
            // Just remove the file name prefix
  return prioFileLine.substr(1);
}

#endif
