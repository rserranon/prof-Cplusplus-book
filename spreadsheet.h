#include <cstddef>
#include "spreadsheetcell.h"

class SpreadSheet {
    public:
        SpreadSheet (size_t width, size_t height);
        void SetCellAt (size_t x, size_t y, SpreadSheeetCell& cell);
        SpreadSheeetCell& GetCellAt(size_t x, size_t y);
    private:
        size_t              m_width     {0};
        size_t              m_height    {0};
        SpreadSheeetCell**  m_cells     {nullptr};
};
