# Linear Regression in C++

This repository contains an implementation of Linear Regression from scratch using C++. The implementation involves creating custom Vector and Matrix classes to handle the necessary operations. Additionally, we use an open-source library for plotting graphs.

## Prerequisites

- C++14 or later
- g++
- [Table-and-Graph-Libs](https://github.com/tdulcet/Table-and-Graph-Libs) for plotting graphs

## Getting Started

### Cloning the Repository

First, clone this repository:

```sh
git clone https://github.com/Khachatryan-nn/linear_regression_cpp.git
```

Next, clone the Table-and-Graph-Libs repository for plotting graphs:
```sh
git clone https://github.com/tdulcet/Table-and-Graph-Libs.git
```

### Building the Project

You can compile the project using the following g++ command:

```sh
g++ -std=c++14 -I Table-and-Graph-Libs main_linalg.cpp ClassMethods.cpp LinearRegression.cpp -o linalg
```

Alternatively, you can use the provided Makefile for easier compilation.
```sh
make run
```

### Running the Executable

Once compiled, run the executable file:

```sh
./linalg
```

### Example Output
The output includes the coefficients of the linear model and a graph plotting the actual vs. predicted values.
