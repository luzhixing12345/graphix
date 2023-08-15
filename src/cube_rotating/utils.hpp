/*
 *Copyright (c) 2022 All rights reserved
 *@description: file analysis for 3D-polyhedron
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <sys/stat.h>
#include <filesystem>
#include "transform.hpp"


const std::string VERTEXT_FILENAME = "vertex.txt";
const std::string EDGE_FILENAME = "edge.txt";
const std::string ROOT_PATH = "3D-polyhedron";

inline bool checkFileExist(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

inline std::string join(const std::string &path1, const std::string &path2, const std::string &path3) {
    return path1 + "/" + path2 + "/" + path3;
}

void readPolyhedronVertex(const std::string &vertex_filename, std::vector<vec3> &vertexs) {

    vec3 point;
    std::vector<float> temp_point;
    std::string line;
    std::string token;
    std::ifstream file_stream;

    file_stream.open(vertex_filename,std::ios::in);
    // read lines and initialize vertex
    while (std::getline(file_stream, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        while (std::getline(ss, token, ',')) {
            temp_point.push_back(std::stof(token));
        }
        point.x = temp_point[0];
        point.y = temp_point[1];
        point.z = temp_point[2];
        vertexs.push_back(point);
        temp_point.clear();
    }
    file_stream.close();
}


void readPolyhedronEdge(const std::string &edge_filename, std::vector<connection> &edges) {

    std::ifstream file_stream;
    std::string line;
    std::string token;
    std::vector<int> temp_edge;
    connection edge;

    file_stream.open(edge_filename, std::ios::in);
    while (std::getline(file_stream, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        while (std::getline(ss, token, ' ')) {
            temp_edge.push_back(std::stoi(token));
        }
        edge.start = temp_edge[0];
        edge.end = temp_edge[1];
        edges.push_back(edge);
        temp_edge.clear();
    }

    file_stream.close();
}

void readPolyhedronFiles(std::string &polyhedron_name, Polyhedron &polyhedron_info) {

    std::string vertex_filename = join(ROOT_PATH, polyhedron_name, VERTEXT_FILENAME);
    std::string edge_filename = join(ROOT_PATH, polyhedron_name, EDGE_FILENAME);

    if (!checkFileExist (vertex_filename) || !checkFileExist (edge_filename)) {
        std::cout << "Error: cannot open file" << std::endl;
        std::cout << "Check README in 3D-polyhedron for more information";
        return;
    }

    readPolyhedronVertex(vertex_filename, polyhedron_info.vertexs);
    readPolyhedronEdge(edge_filename, polyhedron_info.edges);
    
}

#endif