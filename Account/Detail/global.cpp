#include "stdafx.h"
#include "global.h"
#include "DetailDll.h"
#include "Detail.h"
#include "MainFrame.h"

CWnd * __stdcall afxGetMainWnd(void)
{
	return theApp.m_pMainWnd;
}

CWinApp * __stdcall afxGetApp(void)
{
	return &theApp;
}

// DLL CONTRUCT
int WINAPI StartDll(HWND AppHwnd,HINSTANCE &m_hAccount,CWinApp **ppDllApp)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*ppDllApp = afxGetApp();

	//_tcscpy(theApp.m_lpCmdLine,cmdLine);


	theApp.AppHwnd = AppHwnd;

	theApp.m_hAccount = m_hAccount;

	CMainFrame* pFrame = new CMainFrame;
	theApp.m_pMainWnd = pFrame;



	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	// Use message loop for DLL
	MSG msg;

	while(GetMessage(&msg,NULL,0,0))
	{

		theApp.PreTranslateMessage(&msg);
		TranslateMessage(&msg);
		DispatchMessage(&msg);


		//       if(pFrame->FromHandlePermanent(pFrame->GetSafeHwnd()) == NULL)
		if(theApp.m_bExit || ::IsWindow(pFrame->GetSafeHwnd()) == false)
		{

			//   TranslateMessage(&msg);
			//   DispatchMessage(&msg);
			return 1;
		}
	}

	return 1;
}

