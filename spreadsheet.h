#pragma once
#include <cstddef>
#include <ostream>
#include "spreadsheetcell.h"

class SpreadSheet {
    public:
        SpreadSheet (size_t width, size_t height);
        ~SpreadSheet();
        void SetCellAt (size_t x, size_t y, SpreadSheeetCell& cell);
        SpreadSheeetCell& GetCellAt(size_t x, size_t y);
        void VerifyCoordinate(size_t x, size_t y) const;
        size_t GetWidth() const;
        size_t GetHeight() const;
    private:
        size_t              m_width     {0};
        size_t              m_height    {0};
        SpreadSheeetCell**  m_cells     {nullptr};
};

std::ostream& operator<< (std::ostream& os, const SpreadSheet& s);
