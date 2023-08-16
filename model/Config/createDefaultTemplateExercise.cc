#include "Config.ih"
void Config::createDefaultTemplateExercise() const
{
  if (not exists(d_exerciseTemplateFolder))
    create_directory(d_exerciseTemplateFolder);
}
