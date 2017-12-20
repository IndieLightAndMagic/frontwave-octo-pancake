#include "splitter.h"

#include <cstring>
#include <cstdio>
#include <string>
#include <memory>
using namespace std;

/**
 * @brief This class provide binary data for material.
 */
class FrontWave {
	shared_ptr<char> m_pBuffer;
public:
	FrontWave(const shared_ptr<char>);



};




class FrontWaveFactory {

public:
	static shared_ptr<FrontWave> CreateFrontWave(const std::string& rAbsouleFilePath);

};
















