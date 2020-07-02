#include "stdafx.h"
#include "WebSocketsAdapterInterface/Model/ServerSecurityConfiguration.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::websockets_adapter::ServerSecurityConfiguration& expected,
														   const systelab::websockets_adapter::ServerSecurityConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, isWSSEnabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerCertificate());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerPrivateKey());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerDHParam());

		COMPARATOR_ASSERT_EQUAL(expected, actual, isTLSv10Enabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isTLSv11Enabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isTLSv12Enabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isTLSv13Enabled());

		return AssertionSuccess();
	}

}}
