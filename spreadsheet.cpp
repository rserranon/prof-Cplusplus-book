#include "spreadsheet.h"
#include "spreadsheetcell.h"
#include <ostream>
#include <stdexcept>
#include <sys/_types/_size_t.h>

SpreadSheet::SpreadSheet(size_t width, size_t height) : m_width(width), m_height(height) {
    m_cells = new SpreadSheeetCell* [m_width];
    for (size_t i = 0; i < m_width; i++) {
        m_cells[i] = new SpreadSheeetCell[m_height];
    }
}

SpreadSheet::~SpreadSheet() {
    for (size_t x = 0; x < m_width; x++) {
        delete [] m_cells[x];
    }
    delete [] m_cells;
    m_cells = nullptr;
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
