#include "constant.h"

const uint32_t PAGE_SIZE = 4096;
#define TABLE_MAX_PAGES 100
const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

void print_row(Row &row);
void serialize_row(Row* source, void* destination);
void deserizlie_row(void* source, Row* destination);

struct Table {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
    Table();
    ~Table();
};

Table::Table()
{
    this->num_rows = 0;
    for (int i = 0; i < TABLE_MAX_PAGES; i++)
    {
        this->pages[i] = NULL;
    }
}

Table::~Table()
{
}
