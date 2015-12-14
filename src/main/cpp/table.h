#pragma once

#include <string>
#include <vector>

typedef std::vector<int> Path;
typedef std::vector<Path> Paths;

static const int EMPTY = 0;
static const int VISITED = 1;
static const int TARGET = 2;
static const int BORDER = 0xff;

static const int NUMBER_OF_FIELDS = 120;
static const int INVALID_POS = 0;
static const std::string INVALID_COORDINATE = "";

class Table {

    int new_table[NUMBER_OF_FIELDS] = {
        BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER,
        BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  BORDER,
        BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER,
        BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER, BORDER
    };

    size_t number_of_moves;
    int table[NUMBER_OF_FIELDS];
    std::vector<int> dir_knight = { -21, -19, -12,  -8,  8, 12, 19, 21 };

    Path current_path;
    Paths shortest_paths;

    void init();
    void move();
    void search(const int pos, Path current_path);
    std::string getPath(Path path) const;

    public:
    Table();
    ~Table();
    std::string getCoordinate(int pos) const;
    int getPosition(std::string coord) const;
    std::string getShortestPaths() const;
    void find();

    int from_pos;
    int to_pos;

};
