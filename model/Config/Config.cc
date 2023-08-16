#include "Config.ih"

Config::Config()
  : d_pathsToIgnoreForOrder{initPathsToIgnoreForOrder()}
{
  createDefaultMetadataFile();
  createDefaultTemplateExercise();
}
