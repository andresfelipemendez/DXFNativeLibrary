
#if _MSC_VER // this is defined when compiling with Visual Studio
#define EXPORT_API __declspec(dllexport) // Visual Studio needs annotating exported functions with this
#else
#define EXPORT_API // XCode does not need annotating exported functions, so define is empty
#endif


#include <string>

#include "dxflib\dl_dxf.h"
#include "dxflib\dl_creationadapter.h"
#include "MyParser.h"

std::string filePath;
std::string status;

extern "C"
{
	void EXPORT_API OpenFile(const char* str)
	{
		filePath = std::string(str);

		MyParser* parser = new MyParser();
		DL_Dxf* dxf = new DL_Dxf();

		if (!dxf->in(str, parser)) { // if file open failed
			status = " could not be opened.\n";
			return;
		}
		else {
			status = "opening file";
		}
	}

	const EXPORT_API char*  Path(const char* str)
	{
		return filePath.c_str();
	}

	const EXPORT_API char*  GetStatus() {
		return status.c_str();
	}
}