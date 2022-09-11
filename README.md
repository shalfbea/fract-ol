
# fract-ol

This project is about creating graphically beautiful fractals.

## About

This project is part of program in School 21 (Ecole 42).
This will be the opportunity for you to get familiar with the MiniLibX, to discover or use the mathematical notion of complex numbers, to take a peek at the concept of optimization in computer graphics and practice event handling.

## Requirements
- GNU GCC
- GNU Make
- [MiniLibX](https://github.com/42Paris/minilibx-linux) installed

## Installation and usage

1. Download/Clone this repo
	> git clone https://github.com/shalfbea/fract-ol

2. Get into the root directory of project and run make command
	> cd fract-ol ;
	> make

3. To run program simply run ./fract-ol
	> ./fract-ol <fractal_name>
	
Where <fractal_name> is one of the following: Mandelbrot, Julia, BurningShip, Tricorn  
Program'l also show you available parametres  
You can also set params for Julia set, adding them after the name  
Example: ./fractol Julia 0.756 -0.1244 (or use "default" instead)  
Advanced usage: ./fractol "graph" [x y]/default [r g b]/default  

## Technical task
The full task can be found here: [fract-ol_subject](https://github.com/shalfbea/fract-ol/blob/main/fract-ol_subject.pdf)
### Quick summary:
- Only using c language is allowed
- Code-style should respect the [The Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf)
- No memory leaks, segmentation faults, undefined behavior
- Only allowed functions: open, close, read,
write, malloc, free, perror, strerror, exit, all functions of the math
library,  all functions of the MiniLibX
- Can also use [libft](https://github.com/shalfbea/libft) (own implementation of part of the library functions)
- Implement Mandelbrot set and Jilia with different start points
- Using images of mlx is mandatory
- Use different colors
### Bonus:
- Added 2 more fractals
- Zoom in actual mouse position
- Moving by arrow keys
- Color range shift

## Controls
- Arrow keys for moving
- Mouse wheel or clicks for zooming in and out
- R key for reset
- N key to circle throw graphs
- Space for color shifting
- Plus and Minus keys for zooming with static center

## Some screenshots
<img width="599" alt="fractol_example_5" src="https://user-images.githubusercontent.com/92727363/189534450-d5d0ecfb-e355-483f-a1b1-e58a83192611.png">
<img width="580" alt="fractol_example_2" src="https://user-images.githubusercontent.com/92727363/189534452-acc4a040-6601-446d-aa9f-8316f56e92dc.png">
<img width="596" alt="fractol_example_3" src="https://user-images.githubusercontent.com/92727363/189534447-942bfa23-85d9-4258-8a36-0c05ef762d41.png">
<img width="597" alt="fractol_example_4" src="https://user-images.githubusercontent.com/92727363/189534449-33998696-d687-4ba4-8a53-df944b8af5e2.png">
<img width="600" alt="fractol_example_1" src="https://user-images.githubusercontent.com/92727363/189534443-e4f58997-58b4-4505-b832-4553cbf907cf.png">

