# Cube MVP

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/luzhixing12345/cube-rotation/main)
![GitHub](https://img.shields.io/github/license/luzhixing12345/cube-rotation)

## Introduction

This is a project about 3D-cube MVP matrix transformation **without using any 3D graphic library**.

Especially thanks for [YouTube video](https://www.youtube.com/watch?v=kdRJgYO1BJM) which is a great instructional video, and I strongly recommand it.

## Visualization GIF

|cube|regular-triangular-pyramid|regular-octahedron|
|:--:|:--:|:--:|
|![smallcube](https://raw.githubusercontent.com/learner-lu/picbed/master/smallcube.gif)|![tran](https://raw.githubusercontent.com/learner-lu/picbed/master/tran.gif)|![obasd](https://raw.githubusercontent.com/learner-lu/picbed/master/obasd.gif)|

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

first calcuate the centriod of the polyhedron

then use the rotating martix transformation

- 2D

  ![20220626173256](https://raw.githubusercontent.com/learner-lu/picbed/master/20220626173256.png)

- 3D

  ![20220626173340](https://raw.githubusercontent.com/learner-lu/picbed/master/20220626173340.png)

```c++
point.x -= centriod.x;
point.y -= centriod.y;
point.z -= centriod.z;

float rad = 0;

rad = x_axis;
point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

rad = y_axis;
point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

rad = z_axis;
point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;


point.x += centriod.x;
point.y += centriod.y;
point.z += centriod.z;
```
