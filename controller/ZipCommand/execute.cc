#include "ZipCommand.ih"
void ZipCommand::execute()
{
  path setLoc = d_exercises.getSetFolder();
  vp toZip;

  for (const auto &ex: d_exercises.getExercisesAsNumbers())
  {
    path const exPath = d_exercises.getExercisePath(ex);
    if (not validExerciseSubmission(exPath))
      cerr << "WARNING: Exercise " << ex << " will not be accepted" << '\n';
    addPathsFromExercise(setLoc, exPath, toZip);
  }

  string zipName = setLoc.filename().string() + ".zip";
  path zipPath = d_zipLoc/zipName;

  remove(zipPath);

  d_zipper.zip(zipPath, setLoc, toZip);
}
