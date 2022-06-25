# Cube MVP

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/luzhixing12345/cube-rotation/main)
![GitHub](https://img.shields.io/github/license/luzhixing12345/cube-rotation)

## Introduction

This is a project about 3D-cube MVP matrix transformation **without using any 3D graphic library**.

Especially thanks for [YouTube video](https://www.youtube.com/watch?v=kdRJgYO1BJM) which is a great instructional video, and I strongly recommand it.

## Visualization GIF

## Compile and Run

```bash
git clone git@github.com:luzhixing12345/cube-rotation.git
cd cube-rotation
make
```

There are three basic model in `3D-polyhedron` folder, you could use them as

- cube

  ```bash
  main cube
  ```

- regular-triangular-pyramid

  ```bash
  main regular-triangular-pyramid
  ```

- regular-octahedron

  ```bash
  main regular-octahedron
  ```

If you prefer to use a more compilicated polyhedron, see more information in [3D-polyhedron model](3D-polyhedron/README.md)

## About Environment

This project uses [SDL](https://www.libsdl.org/) to create a window and show the result. I have linked all the related files and put them under [src](src) so you could directly compile it with g++ without downloading SDL first.

But if you need to set a permanent SDL workspace, [this video](https://www.youtube.com/watch?v=jUZZC9UXyFs) may help you setup your SDL environment in Vscode.

There are also many excellent library such as OpenGL, MFC, QT, EasyX and so on which can help you create a interactive window and show the picture. Use them as you like.

## Core Solution Method

```c++

```
