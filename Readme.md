# C++11 Delaunay implementation

Implementation of the Bowyer-Watson algorithm, heavily inspired from: http://paulbourke.net/papers/triangulate.

![Delaunay triangulation demo](delaunay.png)

## Requirements

* C++11 compliant compiler
* (OpenGL for the demo)

## How to use

* just include the ```delaunay.hpp``` header file
* do not use in production, more efficient implementation of Delaunay's triangulation can be found elsewhere.


## Example

```
...
#include "delaunay.hpp"
...
std::vector<delaunay::Point<float>> points;
...
const auto triangulation = delaunay::triangulate(point);
...
```
