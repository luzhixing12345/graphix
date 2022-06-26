/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for
 *@author: Zhixing Lu
 *@date: 2022-06-25
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

#include <iostream>
#include "utils.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "wrong input format";
        return 1;
    }

    std::string polyhedron_name = argv[1];
    Screen screen = Screen();
    Polyhedron polyhedron(screen);
    readPolyhedronFiles(polyhedron_name, polyhedron);


    polyhedron.calculateCentroid();
    while (1) {

        polyhedron.rotate();

    }

    return 0;
}
