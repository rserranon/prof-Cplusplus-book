#pragma once
#include <cstddef>
#include <ostream>
#include "spreadsheetcell.h"

class SpreadSheet {
    public:
        SpreadSheet (size_t width, size_t height);
        SpreadSheet(const SpreadSheet& src);        //  Copy constructor
        SpreadSheet(SpreadSheet&& src) noexcept;    //  Move constructor
        ~SpreadSheet();
        SpreadSheet& operator = (const SpreadSheet& rhs);       // Copy assignment operator
        SpreadSheet& operator = (SpreadSheet&& rhs) noexcept;   // Move assignment operator
        void Swap(SpreadSheet& other) noexcept;

        void SetCellAt (size_t x, size_t y, SpreadSheeetCell& cell);
        SpreadSheeetCell& GetCellAt(size_t x, size_t y);
        void VerifyCoordinate(size_t x, size_t y) const;
        size_t GetWidth() const;
        size_t GetHeight() const;
    private:
        size_t              m_width     {0};
        size_t              m_height    {0};
        SpreadSheeetCell**  m_cells     {nullptr};
        static int          s_count;
};

std::ostream& operator<< (std::ostream& os, const SpreadSheet& s);
