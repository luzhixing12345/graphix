# Cube MVP

## Compile and Run

本项目使用 [SDL2](https://www.libsdl.org/) 创建窗口并显示结果.

```bash
sudo apt install libsdl2-dev
```

## About

### About basic rotating core method

first calculate the centriod of the polyhedron

then use the rotating matrix transformation


[more information about MVP]()



### About mouse interaction with rotation

As time flies, the rotation of each axis will restore to a constant value. The `restore_var` is the step.

`change_var` is a constant value which will be multipled with distance to calculate new rotating speech for X or Y axis. Z axis doesn't participate in calcualation.

```c++
float restore_var = 0.00001;
float change_var = 0.0002;
```

### About floating point precision loss

Yes! That's a big problem. As you can see, if you set a high rotating speed. This cube will be seen like below.

![floatproblem](https://raw.githubusercontent.com/learner-lu/picbed/master/floatproblem.gif)

Change float to float doesn't solve the problem, I still couldn't find a good solution.
