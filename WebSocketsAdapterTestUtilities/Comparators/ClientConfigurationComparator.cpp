#include "stdafx.h"
#include "WebSocketsAdapterInterface/Model/ClientConfiguration.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::websockets_adapter::ClientConfiguration& expected,
														   const systelab::websockets_adapter::ClientConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHostAddress());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPort());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isUsingWSS());

		return AssertionSuccess();
	}

}}
