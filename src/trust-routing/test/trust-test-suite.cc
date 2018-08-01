/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

// Include a header file from your module to test.
#include "ns3/trust-table.h"

// An essential include is test.h
#include "ns3/test.h"

// Do not put your test classes in namespace ns3.  You may find it useful
// to use the using directive to access the ns3 namespace directly
using namespace ns3;

// This is an example TestCase.
class TrustTestCase1 : public TestCase
{
public:
  TrustTestCase1 ();
  virtual ~TrustTestCase1 ();

private:
  virtual void DoRun (void);
};

// Add some help text to this case to describe what it is intended to test
TrustTestCase1::TrustTestCase1 ()
  : TestCase ("Trust test case (does nothing)")
{
}

// This destructor does nothing but we include it as a reminder that
// the test case should clean up after itself
TrustTestCase1::~TrustTestCase1 ()
{
}

/**
 * \ingroup aodv-test
 * \ingroup tests
 *
 * \brief Unit test for AODV routing table
 *      Unit test steps:
 *        - Create an empty trust table
 *        - Call LookupTrustEntry => should return false
 *        - Add a new trust entry to trust table
 *        - Call LookupTrustEntry => should return true
 *        - Update trust value in the trust table
 *        - Call LookupTrustEntry => should return true
 *        - Remove trust entry from the trust table
 *        - Call LookupTrustEntry => should return false
 */
struct TrustTableTest : public TestCase
{
  TrustTableTest () : TestCase ("TrustTable")
  {
  }
  virtual void DoRun ()
  {

  }
};


//
// This method is the pure virtual method from class TestCase that every
// TestCase must implement
//
void
TrustTestCase1::DoRun (void)
{
  // A wide variety of test macros are available in src/core/test.h
  NS_TEST_ASSERT_MSG_EQ (true, true, "true doesn't equal true for some reason");
  // Use this one for floating point comparisons
  NS_TEST_ASSERT_MSG_EQ_TOL (0.01, 0.01, 0.001, "Numbers are not equal within tolerance");
}

// The TestSuite class names the TestSuite, identifies what type of TestSuite,
// and enables the TestCases to be run.  Typically, only the constructor for
// this class must be defined
//
class TrustTestSuite : public TestSuite
{
public:
  TrustTestSuite ();
};

TrustTestSuite::TrustTestSuite ()
  : TestSuite ("trust", UNIT)
{
  // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
  AddTestCase (new TrustTestCase1, TestCase::QUICK);
  AddTestCase (new TrustTableTest, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static TrustTestSuite trustTestSuite;

