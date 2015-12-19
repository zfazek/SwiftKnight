#include <iostream>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPPlainHeader.h"
#include "cgicc/HTMLClasses.h"

#include "table.h"

using namespace std;
using namespace cgicc;

int main(int argc, char **argv) {
    string from_field;
    string to_field;

    if (argc == 3) {
        from_field = argv[1];
        to_field = argv[2];
    } else {
        Cgicc cgi;
        cout << HTTPPlainHeader();
        form_iterator p_from = cgi.getElement("from");
        form_iterator p_to = cgi.getElement("to");
        if (p_from != cgi.getElements().end() &&
                p_to != cgi.getElements().end()) {
            from_field = cgi("from");
            to_field = cgi("to");
        }
    }

    if (from_field == to_field) {
        cout << from_field << " - " << to_field << endl;
        return 0;
    }
    Table table;
    table.from_pos = table.getPosition(from_field);
    table.to_pos = table.getPosition(to_field);
    if (table.from_pos == table.to_pos) {
        cout << from_field << " - " << to_field << endl;
        return 0;
    }
    if (table.from_pos != INVALID_POS && table.to_pos != INVALID_POS) {
        table.find();
    }
    cout << table.getShortestPaths() << endl;
    return 0;
}
