
#if _MSC_VER // this is defined when compiling with Visual Studio
#define EXPORT_API __declspec(dllexport) // Visual Studio needs annotating exported functions with this
#else
#define EXPORT_API // XCode does not need annotating exported functions, so define is empty
#endif


#include <string>

std::string filePath;
std::string status;

extern "C"
{
	const EXPORT_API char*  PrintHello(){
		return "Hello";
	}

	int EXPORT_API PrintANumber(){
		return 5;
	}

	int EXPORT_API AddTwoIntegers(int a, int b) {
		return a + b;
	}

	float EXPORT_API AddTwoFloats(float a, float b) {
		return a + b;
	}

	void EXPORT_API OpenFile(const char* str)
	{
		filePath = std::string(str);
		status = "opening file";
	}

	const EXPORT_API char*  Path(const char* str)
	{
		return filePath.c_str();
	}

	const EXPORT_API char*  GetStatus() {
		return status.c_str();
	}
}