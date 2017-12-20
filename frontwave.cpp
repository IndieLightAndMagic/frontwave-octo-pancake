#include "frontwave.h"


FrontWave::FrontWave(shared_ptr<char> pBuffer)
{

}





shared_ptr<FrontWave> FrontWaveFactory::CreateFrontWave(const std::string& rAbsolutePath)
{
	auto ptrToFilename = rAbsolutePath.c_str();
	if (!ptrToFilename) return nullptr;

	auto ptrToFile = fopen(ptrToFilename,"r");
	if (!ptrToFile) return nullptr;

	//Forward
	std::fseek(ptrToFile,0,SEEK_END);
	auto sizeOfFile = ftell(ptrToFile);
	//Rewind
	std::fseek(ptrToFile,0,SEEK_SET);

	//Allocate, Clean & Copy
	auto ptrToBufferForFileContent = make_shared<char>(sizeOfFile+1);
	//auto address2write = reinterpret_cast<void*>(ptrToBufferForFileContent.get());
	auto rawPtr = ptrToBufferForFileContent.get();
	memset(rawPtr, '0', sizeOfFile+1);
	fread(rawPtr, sizeOfFile, 1, ptrToFile);

	//Close File
	fclose(ptrToFile);

	//Create the Object 
	auto frontwave = make_shared<FrontWave>(ptrToBufferForFileContent); 
	return frontwave;
} 