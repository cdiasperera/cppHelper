#ifndef CONFIG_h_1680618520
#define CONFIG_h_1680618520

#include <filesystem>
#include <unordered_map>

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
    static Config &instance()
    {
      if (s_initd)
        return s_singleton;

      s_initd = true;
      s_singleton = Config();
      return s_singleton;
    }
  private:
    Config() = default;
};

#endif
