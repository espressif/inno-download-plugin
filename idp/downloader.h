#pragma once

#include <windows.h>
#include <wininet.h>
#include <map>
#include "tstring.h"
#include "netfile.h"
#include "timer.h"
#include "ui.h"

using namespace std;

class Downloader
{
public:
	Downloader();
	~Downloader();

	void      addFile(tstring url, tstring filename, int size = -1);
	void      clearFiles();
	bool	  downloadFiles();
	DWORDLONG getFileSizes();
	void	  setUI(UI *newUI);
	DWORD	  getLastError();
	tstring	  getLastErrorStr();

protected:
	bool downloadFile(NetFile *netFile);
	void updateProgress(NetFile *file);
	void updateFileName(NetFile *file);
	void updateSpeed(NetFile *file, Timer *timer);
	void updateSizeTime(NetFile *file, Timer *timer);
	void updateStatus(tstring status);
	void storeError();
	
	map<tstring, NetFile *> files; 
	DWORDLONG				filesSize;
	DWORDLONG				downloadedFilesSize;
	HINTERNET				internet;
	UI					   *ui;
	Timer					sizeTimeTimer;
	DWORD					errorCode;
};
