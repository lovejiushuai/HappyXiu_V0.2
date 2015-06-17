// MainFrame.cpp : implementation file
//

#include "stdafx.h"
#include "Detail.h"
#include "MainFrame.h"


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

CMainFrame::CMainFrame()
{

	EnableAutomation();
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CFrameWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMainFrame, CFrameWnd)
END_DISPATCH_MAP()

// Note: we add support for IID_IMainFrame to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {BF9D1EE8-C74B-432F-A1EF-D02FBE6D60CE}
static const IID IID_IMainFrame =
{ 0xBF9D1EE8, 0xC74B, 0x432F, { 0xA1, 0xEF, 0xD0, 0x2F, 0xBE, 0x6D, 0x60, 0xCE } };

BEGIN_INTERFACE_MAP(CMainFrame, CFrameWnd)
	INTERFACE_PART(CMainFrame, IID_IMainFrame, Dispatch)
END_INTERFACE_MAP()


// CMainFrame message handlers


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}
