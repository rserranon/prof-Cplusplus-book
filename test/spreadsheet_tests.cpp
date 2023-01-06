
#include <ostream>
#include <sstream>
#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <string>
#include <boost/test/included/unit_test.hpp>
#include "../spreadsheetcell.h"
#include "../spreadsheet.h"



class SpreadsheetFixture {
    public:
        SpreadsheetFixture() : sc_(), s_(100,100) {
            BOOST_TEST_MESSAGE("SpreadsheetCell Fixture: " + std::to_string(sc_.GetValue())); 
        }
        SpreadSheeetCell    sc_;
        SpreadSheet          s_;
};

BOOST_FIXTURE_TEST_SUITE(spreadsheet_tests, SpreadsheetFixture)

BOOST_AUTO_TEST_CASE(construct_spreadsheetcell)
{
    BOOST_TEST_MESSAGE("construct_spreadsheetcell");
    BOOST_CHECK_LT((sc_.GetValue()-0), 0.000001);
}

BOOST_AUTO_TEST_CASE(construct_spreadsheet) {
    BOOST_TEST_MESSAGE("construct_spreadsheet");
    std::stringstream ss {};
    ss << s_;
    BOOST_CHECK_EQUAL("100,100", ss.str() );
}

BOOST_AUTO_TEST_CASE(set_and_get_cells){
    BOOST_TEST_MESSAGE("set_and_get_cells");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_ );
    BOOST_CHECK_LT((s_.GetCellAt(5,5).GetValue()-1), 0.000001);
}

BOOST_AUTO_TEST_SUITE_END();


