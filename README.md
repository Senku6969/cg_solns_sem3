# Computer Graphics - Important VIVA Questions for Comp Sem 3

## 1. Scan Conversion
Scan conversion is the process of converting geometric data (like lines, shapes, and curves) into a raster format suitable for display on a pixel-based screen. It involves determining which pixels on the screen should be turned on to best represent the intended geometric shapes.

## 2. Rasterization
Rasterization is the process of converting vector graphics (geometric shapes) into a raster image (pixels). It involves determining the color and intensity of each pixel that corresponds to the vector representation.

## 3. Rendering
Rendering is the process of generating an image from a model by means of computer programs. This process encompasses shading, texture mapping, and adding lighting effects to produce a final visual representation.

## 4. Raster Scan vs. Random Scan Displays
- **Raster Scan**:
  - **Definition**: Displays images by scanning pixel rows in a frame buffer.
  - **Advantages**: Simple and compatible with all image types; can display complex images.
  - **Disadvantages**: Lower refresh rates; requires more memory for higher resolutions.
  
- **Random Scan**:
  - **Definition**: Draws lines directly onto the screen in any order, without relying on a pixel grid.
  - **Advantages**: Faster for line drawing and vector graphics; lower memory usage.
  - **Disadvantages**: Not suitable for complex images; limited to simple line graphics.

## 5. Inside-Outside Tests
These tests determine whether a point is inside or outside a polygon by examining the intersections of a ray (from the point) with the polygon's edges. Common algorithms include the Ray-Casting method and the Winding number method.

## 6. Weiler-Atherton Algorithm
The Weiler-Atherton algorithm is a clipping algorithm used for clipping polygons against other polygons. It works by identifying entry and exit points of the clipping polygon, effectively managing the overlapping regions.

## 7. Parallel Projections
Parallel projections are a type of projection where the projection lines are parallel to each other. This includes:
- **Orthographic Projection**: Displays objects without perspective.
- **Oblique Projection**: Displays objects with some perspective, typically at an angle.

## 8. Perspective Projections
Perspective projections simulate depth, making objects appear smaller as they move away from the viewer. They include:
- **One-point Perspective**: All lines converge at a single point.
- **Two-point Perspective**: Lines converge at two points.
- **Three-point Perspective**: Includes height, with three vanishing points.

## 9. Types of Projections and Their Subtypes
- **Orthographic Projection**
  - **Subtypes**: Top, Front, Side views.
  
- **Perspective Projection**
  - **Subtypes**: One-point, Two-point, Three-point perspectives.

## 10. Clipping Algorithms
### Line Clipping Methods
1. **Cohen-Sutherland Algorithm**
   - **Advantages**: Efficient for large numbers of lines; divides space into regions.
   - **Disadvantages**: Not suitable for non-axis-aligned clipping.

2. **Liang-Barsky Algorithm**
   - **Advantages**: Uses parametric equations; faster than Cohen-Sutherland.
   - **Disadvantages**: More complex to implement.

### Polygon Clipping
1. **Sutherland-Hodgman Algorithm**
   - **Advantages**: Simple; works well for convex polygons.
   - **Disadvantages**: Can be inefficient for complex polygons.

2. **Weiler-Atherton Algorithm**
   - **Advantages**: Handles complex polygons; works for both convex and concave shapes.
   - **Disadvantages**: More complicated and slower than simpler methods.

## 11. DDA vs. Bresenham's Line Drawing Algorithms
- **DDA (Digital Differential Analyzer)**
  - **Definition**: Uses floating-point arithmetic to calculate pixel positions incrementally.
  - **Advantages**: Simple and easy to implement.
  - **Disadvantages**: Slower due to floating-point operations.

- **Bresenham's Algorithm**
  - **Definition**: Uses integer arithmetic to efficiently calculate pixel positions.
  - **Advantages**: Fast and produces smooth lines.
  - **Disadvantages**: More complex than DDA.

## 12. Midpoint Circle Drawing Algorithm
The Midpoint Circle Drawing Algorithm is an efficient method to draw a circle by calculating pixel positions based on the circle's radius and center using integer calculations.

## 13. Flood Fill vs. Boundary Fill Techniques
- **Flood Fill**
  - **Advantages**: Simple to implement; fills areas quickly.
  - **Disadvantages**: Can be slow for large areas; may exceed memory limits.

- **Boundary Fill**
  - **Advantages**: Useful for filling non-connected areas; can be efficient.
  - **Disadvantages**: Slower for complex shapes; requires careful boundary definition.

## 14. Anti-Aliasing, Animation, and Rasterization
- **Anti-Aliasing**: Techniques to reduce visual distortions (jaggies) in digital images, improving image quality.
- **Animation**: The process of creating motion by displaying a series of images in rapid succession.
- **Rasterization**: As defined above, converting vector graphics into pixels.

## 15. 3rd Back Surface
This term typically refers to the third surface in a rendering context, often used in multi-surface algorithms where visibility or shading calculations involve multiple surfaces or layers.

## 16. Bézier Curves
Bézier curves are parametric curves used in computer graphics for modeling smooth curves. They are defined by control points, with the most common being quadratic (2 control points) and cubic (3 control points).

---

# Algorithms in C

## DDA Line Drawing Algorithm
```c
#include <graphics.h> // Include graphics library
#include <math.h>    // Include math library

void DDA_line(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = x0, y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Replace with your pixel plotting function
        x += x_inc;
        y += y_inc;
    }
}
```

## BRESENHAM Line Drawing Algorithm
```c
#include <graphics.h> // Include graphics library

void Bresenham_line(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int sx = (dx > 0) ? 1 : -1;
    int sy = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);

    if (dx > dy) {
        int err = dx / 2;
        while (x0 != x1) {
            putpixel(x0, y0, WHITE); // Replace with your pixel plotting function
            err -= dy;
            if (err < 0) {
                y0 += sy;
                err += dx;
            }
            x0 += sx;
        }
    } else {
        int err = dy / 2;
        while (y0 != y1) {
            putpixel(x0, y0, WHITE); // Replace with your pixel plotting function
            err -= dx;
            if (err < 0) {
                x0 += sx;
                err += dy;
            }
            y0 += sy;
        }
    }
}
```

## Midpoint Circle Drawing Algorithm
```c
#include <graphics.h> // Include graphics library

void Midpoint_circle(int x_center, int y_center, int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    
    putpixel(x_center + x, y_center + y, WHITE); // Replace with your pixel plotting function
    putpixel(x_center - x, y_center + y, WHITE);
    putpixel(x_center + x, y_center - y, WHITE);
    putpixel(x_center - x, y_center - y, WHITE);
    putpixel(x_center + y, y_center + x, WHITE);
    putpixel(x_center - y, y_center + x, WHITE);
    putpixel(x_center + y, y_center - x, WHITE);
    putpixel(x_center - y, y_center - x, WHITE);

    while (x < y) {
        x++;
        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
        putpixel(x_center + x, y_center + y, WHITE); // Replace with your pixel plotting function
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);
    }
}
```


