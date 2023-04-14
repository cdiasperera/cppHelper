#ifndef CONFIG_h_1680618520
#define CONFIG_h_1680618520

#include <filesystem>
#include <unordered_map>

// Singleton object containing configuration for program, obtained from a
// configuration file.
class Config
{
  using fsPath = std::filesystem::path;

                          // Singleton members
  static bool s_initd;
  static Config s_singleton;

                          // Configuration parameters
  fsPath d_configFolder = fsPath(getenv("HOME"))/".cppHelper";
  fsPath d_exerciseTemplateFolder = d_configFolder/"exercise";

  public:
    fsPath const &templateFilePath() const;
    static Config &instance();
  private:
    Config() = default;
};
inline Config::fsPath const &Config::templateFilePath() const
{
  return d_exerciseTemplateFolder;
}

#endif
