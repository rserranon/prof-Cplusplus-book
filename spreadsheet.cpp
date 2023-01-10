#include "spreadsheet.h"
#include "spreadsheetcell.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <type_traits>

int SpreadSheet::s_count = 0;

void Swap(SpreadSheet& first, SpreadSheet& second) noexcept {
    first.Swap(second);
}

SpreadSheet::SpreadSheet(size_t width, size_t height) : m_width(width), m_height(height) {
    std::cout << "Constructor" << std::endl;
    s_count++;
    std::cout << s_count << std::endl;
    m_cells = new SpreadSheeetCell* [m_width];
    for (size_t i = 0; i < m_width; i++) {
        m_cells[i] = new SpreadSheeetCell[m_height];
    }
}

SpreadSheet::SpreadSheet(const SpreadSheet& src) : SpreadSheet {src.m_width, src.m_height} {
    std::cout << "Copy constructor" << std::endl;
    for(size_t x=0; x < m_width; x++) {
        for (size_t y=0; y < m_height; y++) {
            m_cells[x][y] = src.m_cells[x][y];
        }
    }
}

SpreadSheet::SpreadSheet(SpreadSheet&& src) noexcept {
    std::cout << "Move constructor" << std::endl;
    s_count++;
    std::cout << s_count << std::endl;
    Swap(src);
}

SpreadSheet::~SpreadSheet() {
    std::cout << "Destructor" << std::endl;
    s_count--;
    std::cout << s_count << std::endl;
    for (size_t x = 0; x < m_width; x++) {
        delete [] m_cells[x];
    }
    delete [] m_cells;
    m_cells = nullptr;
}

SpreadSheet& SpreadSheet::operator = (const SpreadSheet &rhs) {
    std::cout << "Copy assignment operator" << std::endl;
    SpreadSheet temp { rhs };
    Swap(temp);
    return *this;
}

SpreadSheet& SpreadSheet::operator = (SpreadSheet&& rhs) noexcept {
    std::cout << "Move assignment operator" << std::endl;
    Swap(rhs);
    return *this;
}

void SpreadSheet::Swap(SpreadSheet &other) noexcept {
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void SpreadSheet::SetCellAt (size_t x, size_t y, SpreadSheeetCell& cell) {
    VerifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadSheeetCell& SpreadSheet::GetCellAt(size_t x, size_t y){
    VerifyCoordinate(x, y);
    return m_cells[x][y];
}

void SpreadSheet::VerifyCoordinate(size_t x, size_t y) const {
    if (x > m_width || y > m_height) {
        throw std::out_of_range { "Coordinate(s) out of range" };
    }
}
        
size_t SpreadSheet::GetWidth() const {
    return m_width;
}
size_t SpreadSheet::GetHeight() const {
    return m_height;
}


std::ostream& operator << (std::ostream& os, const SpreadSheet& s) {
    os << s.GetWidth() << "," << s.GetHeight();
    return os;
}
