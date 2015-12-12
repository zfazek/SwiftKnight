#include "table.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

Table::Table() {
    init();
}

Table::~Table() {}

void Table::init() {
    for (int i = 0; i < 120; i++) {
        table[i] = new_table[i];
    }
    number_of_moves = 64;
    current_path.clear();
    shortest_paths.clear();
}

void Table::search(const int pos, Path current_path) {
    size_t current_path_size = current_path.size();
    if (current_path_size > number_of_moves) {
        return;
    }
    for (const auto dir : dir_knight) {
        int new_pos = pos + dir;
        if (table[new_pos] == 0xff) {
            continue;
        }
        if (table[new_pos] == 1) {
            continue;
        }
        if (table[new_pos] == 2) {
            current_path.push_back(new_pos);
            current_path_size = current_path.size();
            if (current_path_size < number_of_moves) {
                shortest_paths.clear();
                shortest_paths.push_back(current_path);
                number_of_moves = current_path_size;
            } else if (current_path_size == number_of_moves) {
                shortest_paths.push_back(current_path);
            }
            return;
        }
        table[new_pos] = 1;
        current_path.push_back(new_pos);
        search(new_pos, current_path);
        table[new_pos] = 0;
        current_path.pop_back();
    }
    return;
}

void Table::find() {
    init();
    move();
    current_path.push_back(from_pos);
    search(from_pos, current_path);
}

void Table::move() {
    table[from_pos] = 1;
    table[to_pos] = 2;
}

string Table::getCoordinate(int pos) const {
    if (pos < 0 || pos > 119) {
        return "";
    }
    if (table[pos] == 0xff) {
        return "";
    }
    return "" + string(1, 'a' + (pos - 1) % 10) + string(1, '0' + pos / 10 - 1);
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
    return 10 * (coord[1] - '0' + 1) + (tolower(coord[0]) - 'a' + 1);
}

string Table::getPath(Path path) const {
    string ret;
    for (const auto pos : path) {
        ret += getCoordinate(pos) + " - ";
    }
    return ret.substr(0, ret.size() - 3);
}

string Table::getShortestPaths() const {
    if (shortest_paths.empty()) {
        return "No solution";
    }
    string ret;
    for (const auto path : shortest_paths) {
        ret += getPath(path) + ";<p>";
    }
    return ret;
}
