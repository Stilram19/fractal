# 42_FRACTAL

## About

This project aims to create visually striking fractals such as the Mandelbrot and Julia sets. It was my first adventure in graphics projects of the 42 common core curriculum. Here is the link to the [subject](https://cdn.intra.42.fr/pdf/pdf/121932/en.subject.pdf)

![](resources/images/about_project.png)

## What I learned from this project:

During the development of this project, I've learned several important concepts including:

- **PixelPixel and image memory representation**: Understanding how pixels and
images are stored in memory, crucial for manipulating graphical data, since the project is about coloring an image putting pixel by pixel. 
- **User input Handling (through Mouse, keyboard)**: During the project, I implementated zooming and translation functionalities through both mouse and keyboard events. This involved understanding how to interpret user input, such as mouse wheel scrolling or keyboard arrow keys, to adjust the viewport and manipulate the displayed fractal accordingly. This added an interactive dimension to the project, allowing users to explore fractals dynamically and focus on specific regions of interest with ease.
- **Mathematical transformations for fractal generation**: Applying mathematical transformations to generate fractal patterns and structures.
- **Performance optimization in rendering**: Enhancing rendering speed and efficiency to manage computationally intensive fractal calculations by minimizing overhead. For instance, optimizing resource usage by consolidating crucial information into a single global structure stored in the data segment, thus streamlining access and reducing processing time.
- **Coordinate systems and transformations**: Understanding coordinate systems and transformations to map fractal space onto the screen.
- **Debugging and troubleshooting graphical applications**: Identifying and
resolving issues in graphical programs, ensuring smooth operation.

# my_42_project

![](resources/images/my_project.png)

![](resources/videos/juliaSet.mp4)

## Installation and Usage

This project was built first time in mac, using the mlx 42 libarary (macos version), but was translated to SDL since the linux mlx version isn't responding to user input (Keyboard, Mouse).

1. Install SDL:
   ```bash
      sudo apt update && sudo apt install libsdl2-dev libsdl2-image-dev
   ```

2. Clone the repository to your local machine:

   ```bash
   git clone git@github.com:Stilram19/fractal.git
   ```

3. Navigate to the repository's directory:

    ```bash
    cd fractal
    ```

3. Compile and Run the program:
   To make the program render Julia Set (Move the mouse and let the magic happen):
   ``` bash
   make julia
   ```

   To make the program render Mandlbrot Set:
   ``` bash
   make mandelbrot
   ```

## Concepts you cannot do without (for students):

- [Data segment](https://en.wikipedia.org/wiki/Data_segment)
- [memory leaks](https://en.wikipedia.org/wiki/Memory_leak)
- [I/O Buffers](https://stackoverflow.com/questions/27993971/understanding-buffering-in-c)
- [static variables](https://www.geeksforgeeks.org/static-variables-in-c/)
- [stack frame](https://en.wikipedia.org/wiki/Call_stack)
- [pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming))  
- [Endianness](https://en.wikipedia.org/wiki/Endianness)  
- [Pointer arithmetic](https://www.geeksforgeeks.org/pointer-arithmetics-in-c-with-examples/)  
- [two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)    
- [integer promotion](https://www.geeksforgeeks.org/integer-promotions-in-c/)
