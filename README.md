# FdF
a simplified 3D graphic representation of a landscape
![screenshot](/fdf_basictest.gif)
## Description
A simple 3D wireframe landscape rendered from a given height Z at each X,Y position. 

Colors transition between 3 colors based on max and min height.

Keyhooks for rotation and translation.

Developed using a library for single pixel printing and keyhooks.

## Compile and Run
```
make
./fdf [FILENAME]
```
for the example above:
```
./fdf maps/basictest.fdf
```
recommended included maps:

	42.fdf
	pyramide.fdf
	mars.fdf

## View Controls

Translation:

	w: up
	a: left
	s: down
	d: right

