#include "TestHarness.h"

#include <string>
#include <iostream>

using namespace std;

#include "sof/instantiation/ObjectCreator.h"
#include "sof/framework/IBundleActivator.h"

#include "ITest.h"
#include "BaseTestClass.h"
#include "TestClass.h"
#include "ITestImpl.h"

#include "UnitTestLogger.h"

using namespace sof::instantiation;
using namespace sof::framework;

int main()
{	
	UnitTestLogger::getInstance().log( Logger::LOG_DEBUG, "[osgi_sof_test#main] *** Begin tests...." );
    TestResult tr;
    TestRegistry::runAllTests(tr);
	return 0;
}




