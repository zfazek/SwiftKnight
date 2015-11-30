#pragma once

#include <string>

class Table {

    int new_table[120] = {
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };

    int table[120];

    int dir_knight[8] = { -21, -19, -12,  -8,  8, 12, 19, 21 };

    void init();

    public:
    Table();
    ~Table();
    std::string getCoordinate(int pos) const;
    int getPosition(std::string coord) const;
};