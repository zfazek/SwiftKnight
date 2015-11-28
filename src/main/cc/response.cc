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
    int from_pos;
    int to_pos;
    Table table;
    if (argc == 3) {
        from_field = argv[1];
        to_field = argv[2];
    } else {
        Cgicc cgi;
        cout << HTTPPlainHeader() << endl;
        form_iterator p_from = cgi.getElement("from");
        form_iterator p_to = cgi.getElement("to");
        if (p_from != cgi.getElements().end() &&
                p_to != cgi.getElements().end()) {
            from_field == **p_from;
            to_field == **p_to;
        }
    }
    from_pos = table.getPosition(from_field);
    to_pos = table.getPosition(to_field);
    cout << from_field << " - " << to_field << endl;
    cout << from_pos << " - " << to_pos << endl;
}
