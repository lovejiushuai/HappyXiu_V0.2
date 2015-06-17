// DLL CONTRUCT
#ifdef DLL_EXPORTS
#define DLL_API extern "C" _declspec(dllexport)
#else
#define DLL_API extern "C" _declspec(dllimport)
#endif

int WINAPI StartDll(HWND AppHwnd,HINSTANCE &m_hAccount,CWinApp **ppDllApp);