/*
 * MATLAB Compiler: 4.10 (R2009a)
 * Date: Sat Apr 23 19:59:42 2016
 * Arguments: "-B" "macro_default" "-o" "Untitled1" "-W" "WinMain:Untitled1"
 * "-d" "C:\Users\Foxtrot\Documents\Main Project\Color DWT-SVD
 * watermarking\New\FINAL\Final\Untitled1\src" "-T" "link:exe" "-v"
 * "C:\Users\Foxtrot\Documents\Main Project\Color DWT-SVD
 * watermarking\New\FINAL\Final\FINAL.m" "-a" "C:\Users\Foxtrot\Documents\Main
 * Project\Color DWT-SVD watermarking\New\FINAL\Final\host.jpg" "-a"
 * "C:\Users\Foxtrot\Documents\Main Project\Color DWT-SVD
 * watermarking\New\FINAL\Final\host2.jpg" "-a"
 * "C:\Users\Foxtrot\Documents\Main Project\Color DWT-SVD
 * watermarking\New\FINAL\Final\watermark.jpg" "-a"
 * "C:\Users\Foxtrot\Documents\Main Project\Color DWT-SVD
 * watermarking\New\FINAL\Final\watermark2.jpg" 
 */

#include <stdio.h>
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

extern mclComponentData __MCC_Untitled1_component_data;

#ifdef __cplusplus
}
#endif

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_Untitled1_C_API 
#define LIB_Untitled1_C_API /* No special import/export declaration */
#endif

LIB_Untitled1_C_API 
bool MW_CALL_CONV Untitled1InitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler
)
{
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
  if (!mclInitializeComponentInstanceWithEmbeddedCTF(&_mcr_inst,
                                                     &__MCC_Untitled1_component_data,
                                                     true, NoObjectType,
                                                     ExeTarget, error_handler,
                                                     print_handler, 1675473, NULL))
    return false;
  return true;
}

LIB_Untitled1_C_API 
bool MW_CALL_CONV Untitled1Initialize(void)
{
  return Untitled1InitializeWithHandlers(mclDefaultErrorHandler,
                                         mclDefaultPrintHandler);
}

LIB_Untitled1_C_API 
void MW_CALL_CONV Untitled1Terminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

int run_main(int argc, const char **argv)
{
  int _retval;
  /* Generate and populate the path_to_component. */
  char path_to_component[(PATH_MAX*2)+1];
  separatePathName(argv[0], path_to_component, (PATH_MAX*2)+1);
  __MCC_Untitled1_component_data.path_to_component = path_to_component; 
  if (!Untitled1Initialize()) {
    return -1;
  }
  argc = mclSetCmdLineUserData(mclGetID(_mcr_inst), argc, argv);
  _retval = mclMain(_mcr_inst, argc, argv, "FINAL", 0);
  if (_retval == 0 /* no error */) mclWaitForFiguresToDie(NULL);
  Untitled1Terminate();
#if defined( _MSC_VER)
  PostQuitMessage(0);
#endif
  mclTerminateApplication();
  return _retval;
}

#if defined( _MSC_VER)

#define argc __argc
#define argv __argv

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, const char **argv)

#endif
{
  if (!mclInitializeApplication(
    __MCC_Untitled1_component_data.runtime_options,
    __MCC_Untitled1_component_data.runtime_option_count))
    return 0;
  
  return mclRunMain(run_main, argc, argv);
}