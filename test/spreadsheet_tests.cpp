
#include <algorithm>
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
            BOOST_TEST_MESSAGE("Spreadsheet     Fixture: "); 
        }
        SpreadSheeetCell    sc_;
        SpreadSheet          s_;
};

BOOST_FIXTURE_TEST_SUITE(spreadsheet_tests, SpreadsheetFixture)

BOOST_AUTO_TEST_CASE(construct_spreadsheetcell)
{
    BOOST_TEST_MESSAGE("test_construct_spreadsheetcell");
    BOOST_CHECK_LT((sc_.GetValue()-0), 0.000001);
}

BOOST_AUTO_TEST_CASE(construct_spreadsheet) {
    BOOST_TEST_MESSAGE("test_construct_spreadsheet");
    std::stringstream ss {};
    ss << s_;
    BOOST_CHECK_EQUAL("100,100", ss.str() );
}

BOOST_AUTO_TEST_CASE(set_and_get_cells){
    BOOST_TEST_MESSAGE("test_set_and_get_cells");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_ );
    BOOST_CHECK_LT((s_.GetCellAt(5,5).GetValue()-1), 0.000001);
}

BOOST_AUTO_TEST_CASE(copy_spreadsheet) {
    BOOST_TEST_MESSAGE("test_copy_spreadsheet");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_ );
    SpreadSheet s2 = s_; // Construct and copy the object, the copy constructor gets called 
    BOOST_CHECK_LT((s2.GetCellAt(5,5).GetValue()-1), 0.000001);
}

BOOST_AUTO_TEST_CASE(copy_assignment_spreadsheet) {
    BOOST_TEST_MESSAGE("test_copy_assignment_spreadsheet");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_ );
    SpreadSheet s2 {100, 100};
    s2 = s_; // Copy the object, the copy assignment operator gets called 
    BOOST_CHECK_LT((s2.GetCellAt(5,5).GetValue()-1), 0.000001);
}

BOOST_AUTO_TEST_CASE(move_constructor) {
    BOOST_TEST_MESSAGE("test_move_constructor");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_);
    SpreadSheet s2(std::move(s_));
    BOOST_CHECK_LT((s2.GetCellAt(5,5).GetValue()-1), 0.000001);
    // BOOST_TEST(&s_ == nullptr);
}

BOOST_AUTO_TEST_CASE(move_assignment_constructor) {
    BOOST_TEST_MESSAGE("test_move_assignment_constructor");
    sc_.SetValue(1);
    s_.SetCellAt(5, 5, sc_);
    SpreadSheet s2{100, 100};
    s2 = std::move(s_);
    BOOST_CHECK_LT((s2.GetCellAt(5,5).GetValue()-1), 0.000001);
    // BOOST_TEST(&s_ == nullptr);
}


BOOST_AUTO_TEST_SUITE_END();


