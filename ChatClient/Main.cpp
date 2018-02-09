// ChatClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <exdisp.h>
#include <comdef.h>
#include "ChatMainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr))
		return 0;

	shared_ptr<ChatMainWnd> mainWnd(new ChatMainWnd);
	if (mainWnd == NULL)
		return 0;
	mainWnd->Create(NULL, L"聊天", UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWnd->CenterWindow();
	mainWnd->ShowWindow();

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}

