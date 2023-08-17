
# cube-rotating

|                                          cube                                          |                          regular-triangular-pyramid                          |                               regular-octahedron                               |
| :------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------: | :----------------------------------------------------------------------------: |
| ![smallcube](https://raw.githubusercontent.com/learner-lu/picbed/master/smallcube.gif) | ![tran](https://raw.githubusercontent.com/learner-lu/picbed/master/tran.gif) | ![obasd](https://raw.githubusercontent.com/learner-lu/picbed/master/obasd.gif) |

## 编译与运行

```bash
## compile
cd src/cube_rotating
make

## run
./main cube
./main regular-triangular-pyramid
./main regular-octahedron
```

## 代码结构介绍

```bash
├── 3D-polyhedron                   # 一些 3D 模型的顶点/边的信息
│   ├── README.md
│   ├── cube
│   │   ├── edge.txt
│   │   └── vertex.txt
│   ├── regular-octahedron
│   │   ├── edge.txt
│   │   └── vertex.txt
│   └── regular-triangular-pyramid
│       ├── edge.txt
│       └── vertex.txt
├── Makefile
├── main.cpp
├── screen.cpp
├── screen.hpp
├── transform.cpp
├── transform.hpp
└── utils.hpp
```



There are three basic model in `3D-polyhedron` folder, you could use them as




如果您希望使用更复杂的多面体

首先计算多面体的中心点, 然后使用旋转矩阵变换

- 2D

  ![20220626173256](https://raw.githubusercontent.com/learner-lu/picbed/master/20220626173256.png)

- 3D

  ![20220626173340](https://raw.githubusercontent.com/learner-lu/picbed/master/20220626173340.png)

> [2.MVP矩阵运算](https://zhuanlan.zhihu.com/p/478332678)

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

## 参考

- [3D Graphics With Draw Pixel - Rotating Cube SDL2 C++ Project](https://www.youtube.com/watch?v=kdRJgYO1BJM)
- [2.MVP矩阵运算](https://zhuanlan.zhihu.com/p/478332678)