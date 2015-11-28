#include "table.h"
#include <string>

using namespace std;

Table::Table() {
    init();
}

Table::~Table() {}

void Table::init() {
    for (int i = 0; i < 120; i++) {
        table[i] = new_table[i];
    }
}

string Table::getCoordinate(int pos) const {
    if (pos < 0 || pos > 119) {
        return "";
    }
    if (table[pos] == 0xff) {
        return "";
    }
    return "" + (char)('a' + (pos - 1) % 10) + (pos / 10 - 1);
}

int Table::getPosition(string coord) const {
    if (coord.size() != 2) {
        return 0;
    }
    if (tolower(coord[0]) < 'a' || tolower(coord[0]) > 'h') {
        return 0;
    }
    if (coord[1] < '1' || coord[1] > '8') {
        return 0;
    }
    return 10 * (tolower(coord[0]) - 'a' + 2) +
        coord[1] - '0';
}

