#include "stdafx.h"
#include "WebSocketsAdapterInterface/Model/ServerConfiguration.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::websockets_adapter::ServerConfiguration& expected,
														   const systelab::websockets_adapter::ServerConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPort());

		const auto& expectedSecurityConfiguration = expected.getSecurityConfiguration();
		const auto& actualSecurityConfiguration = actual.getSecurityConfiguration();
		AssertionResult securityConfigurationResult = EntityComparator()(expectedSecurityConfiguration, actualSecurityConfiguration);
		if (!securityConfigurationResult)
		{
			return AssertionFailure() << "Different security configuration: " << securityConfigurationResult.message();
		}

		return AssertionSuccess();
	}

}}
