#include "spreadsheetcell.h"

double SpreadSheeetCell::GetValue() {
    return m_Value;
}

void SpreadSheeetCell::SetValue(double value) {
    m_Value = value;
}
