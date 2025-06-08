# fdf

This project is a wireframe modelling program that displays a map using 42's graphics library minilibx.

## Things Learnt:
- line drawing algorithms: DDA, Bresenham's, Xiaolin Wu's Anti-aliasing <br>
- affine transformation matrices for 3D objects <br>
- proper sequencing / ordering of transformations <br>
- different types of projections: parallel, perspective, isometric, oblique... <br>
- how to create a hue function

## Resources: <br>
minilibx: https://aurelienbrabant.fr/blog <br>
Endianness: https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/ <br>
Bresenham's line drawing alg: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm <br>
Perspective Projection: https://www.youtube.com/watch?v=U0_ONQQ5ZNM <br>

## Snapshots:
![image](https://github.com/rsoo23/fdf/assets/81731553/84d8cfd4-4cc2-4a85-9ffb-3614076f69dd)
![image](https://github.com/rsoo23/fdf/assets/81731553/45186a50-47b0-4bef-aedc-2756bd9eb925)
![image](https://github.com/rsoo23/fdf/assets/81731553/8f8d0794-5ccf-49fc-b977-7e1d717c6c9a)

## Setup (Linux)
1. Install the dependencies for minilibx
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
2. clone the repository
```bash
git clone https://github.com/rsoo23/fdf.git fdf
```
3. make the executable
```bash
make
```
4. run the executable with the file you want
```bash
./fdf maps/filename.fdf
```

To be able to run the program on other OSes, you can refer to this guide:
[minilibx guide](https://harm-smits.github.io/41docs/libs/minilibx/getting_started.html)

## Controls (MacOS Keys)
| Key Press | Function |
|-----------|----------|
| I         | isometric projection |
| O         | oblique projection |
| T         | top view |
| R         | reset |
| q/a       | rotate about x-axis |
| w/s       | rotate about y-axis |
| e/d       | rotate about z-axis |
| z/x       | dec. / inc. scale |
| f/g       | dec. / inc. z scale |
| c/v       | dec. / inc. base hue height |
| h/j       | cycle through base hues |
| k/l       | cycle through non-base hues |
| u         | increase oblique angle |
