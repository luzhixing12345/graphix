/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for
 *@author: Zhixing Lu
 *@date: 2022-06-25
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

#include <sys/stat.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

/**
 * @brief 读取多面体顶点信息
 *
 * @param vertex_filename
 * @param vertexs
 */
void readPolyhedronVertex(const std::string &vertex_filename, std::vector<vec3> &vertexs) {
    vec3 point;
    std::vector<float> temp_point;
    std::string line;
    std::string token;
    std::ifstream file_stream;

    file_stream.open(vertex_filename, std::ios::in);
    // read lines and initialize vertex
    while (std::getline(file_stream, line)) {
        if (line.empty())
            continue;
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

/**
 * @brief 读取多面体边信息
 *
 * @param edge_filename
 * @param edges
 */
void readPolyhedronEdge(const std::string &edge_filename, std::vector<connection> &edges) {
    std::ifstream file_stream;
    std::string line;
    std::string token;
    std::vector<int> temp_edge;
    connection edge;

    file_stream.open(edge_filename, std::ios::in);
    while (std::getline(file_stream, line)) {
        if (line.empty())
            continue;

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

/**
 * @brief 在 3D-polyhedron 搜索对应名字的多面体, 获取其 顶点 + 边 信息
 *
 * @param polyhedron_name
 * @param polyhedron_info
 */
void readPolyhedronFiles(std::string &polyhedron_name, Polyhedron &polyhedron_info) {
    std::string vertex_filename = join(ROOT_PATH, polyhedron_name, VERTEXT_FILENAME);
    std::string edge_filename = join(ROOT_PATH, polyhedron_name, EDGE_FILENAME);
    if (!checkFileExist(vertex_filename) || !checkFileExist(edge_filename)) {
        std::cout << "Error: cannot open file" << std::endl;
        std::cout << "Check README in 3D-polyhedron for more information";
        return;
    }

    readPolyhedronVertex(vertex_filename, polyhedron_info.vertexs);
    readPolyhedronEdge(edge_filename, polyhedron_info.edges);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "wrong input format: ./main <type>\n";
        return 1;
    }

    std::string polyhedron_name = argv[1];
    Screen screen = Screen();
    Polyhedron polyhedron(screen);
    readPolyhedronFiles(polyhedron_name, polyhedron);

    // 计算旋转中心点
    polyhedron.calculateCentroid();

    
    while (1) {
        polyhedron.rotate();
    }

    return 0;
}
