#include "GenFolderTest.ih"

bool GenFolderTest::hasMainArgs(
  GenFolder const &genFolder,
  ExpectedArgs const &expectedArgs
)
{
  return genFolder.d_cpyInto == get<std::string>(expectedArgs)
    && genFolder.d_set == get<SET_ARG_POS_EXP_ARGS>(expectedArgs)
    && genFolder.d_set == get<EXSTART_ARG_POS_EXP_ARGS>(expectedArgs)
    && genFolder.d_set == get<EXEND_ARG_POS_EXP_ARGS>(expectedArgs);
}
