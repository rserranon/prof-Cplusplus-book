
#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <string>
#include <boost/test/included/unit_test.hpp>
#include "../spreadsheetcell.h"


class SpreadsheetFixture {
    public:
        SpreadsheetFixture() : sc_() {
            BOOST_TEST_MESSAGE("SpreadsheetCell Fixture: " + std::to_string(sc_.GetValue())); 
        }
        SpreadSheeetCell sc_;
};

BOOST_FIXTURE_TEST_SUITE(spreadsheet_tests, SpreadsheetFixture)

BOOST_AUTO_TEST_CASE(spreadsheet_construct_spreadsheetcell)
{

    BOOST_CHECK_LT((sc_.GetValue()-0), 0.000001);
}



BOOST_AUTO_TEST_SUITE_END();


