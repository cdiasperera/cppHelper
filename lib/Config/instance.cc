#include "Config.ih"

Config &Config::instance()
{
  if (s_initd)
    return s_singleton;

  s_initd = true;
  s_singleton = Config();
  return s_singleton;
}
