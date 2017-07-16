#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Indicium-Supra\Client\Render.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{

	public:	
		TEST_METHOD(failInitialize)
		{
			SetParam("process", "0");
			Assert::AreEqual(-1, TextCreate("Arial", 18, false, false, 35, 35, 0x50FF00FF, "test", true, true));
		}
	};
}