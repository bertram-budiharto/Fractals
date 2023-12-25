// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 10: Recursion and Fractals
// Purpose: A program that will generate these different fractal shapes: Sierpinski Triangle, Shrinking Squares, Spiral Squares, Circular Lace, Snowflake, Tree, Fern, Spiral of Spirals

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "gfx.h"

// a function to construct the sierpinski triangle puzzle
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );

// a function to draw a triangle
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );

// a function to construct the shrinking square puzzle
void shrinking (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double length );

// a function to draw a square
void drawSquares (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

// a function to construct the spiral squares puzzle
void spiral(double x, double y, double radius, double length, double angle);

// a function to construct the circular lace puzzle
void circular(double x, double y, double radius, double angle);

// a function to construct the snowflake puzzle
void snowflake(double x1, double y1, double radius);

// a function to construct the tree puzzle
void tree(double x, double y, double radius, double angle);

// a function to construct the ferns puzzle
void ferns(double x, double y, double radius, double angle);

// a function to construct the spiral of spirals puzzle
void spiral1(double x, double y, double radius, double angle);

int main() {
	int width = 700, height = 700, mrgn = 20; // sets up the dimension of the window
	int center = 350; // center of the window 

	gfx_open(width, height, "Fractal Puzzles"); // opens up the the window
	
	while (1) {
		char c = gfx_wait(); // waits for the user input
		gfx_clear(); // clears the screen
		if (c == '1') // in the case of key 1 (sierpinski triangle)
			sierpinski(mrgn, mrgn, width-mrgn, mrgn, width/2, height - mrgn); // calls the sierpinski function
		else if (c == '2')  // in the case of key 2 (shrinking squares)
			shrinking(center - 150, center - 150, center + 150, center - 150, center + 150, center + 150, center - 150, center + 150, 300); // calls in the shrinking function
		else if (c == '3')  // in the case of key 3 (spiral squares)
			spiral(350, 350, 330, 50, 0); // calls in the spiral function
		else if (c == '4') // in the case of key 4 (circular lace)
			circular(center, center, 200, 0); // calls in the circular function
		else if (c == '5')  // in the case of key 5 (snowflake)
			snowflake(center, center, 250); // calls in the snowflake function
		else if (c == '6') // in the case of key 6 (tree)
			tree(center, 690, 250, M_PI/2); // calls in the tree function 
		else if (c == '7') // in the case of key 7 (fern)
			ferns(center, 690, 300, M_PI/2); // calls in the ferns function
		else if (c == '8') // in the case of key 8 (spiral of spirals)
			spiral1(center, center, 2*center, 0); // calls in the spiral1 function
		else if (c == 'q') { // in the case of key 'q' (quit)
			break; // exits the program
		}
	}	 
	
	return 0;
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 ) {
	if ( abs (x2-x1) < 5) {  
		return;
	}
	
	drawTriangle( x1, y1, x2, y2, x3, y3 );

	sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
	sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
	sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );

	// usleep(10000);
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 ) {
	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x3, y3, x1, y1);
}

void shrinking (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double length )
{
	if (length < 0.5 ) {
		return;
	}
	else {
		length = length * 4/10;
		drawSquares( x1, y1, x2, y2, x3, y3, x4, y4 );

		shrinking( x1 - length/2, y1 - length/2, x1 + length/2, y1 - length/2, x1 + length/2, y1 + length/2, x1 - length/2, y1 + length/2, length);
		shrinking( x2 - length/2, y2 - length/2, x2 + length/2, y2 - length/2, x2 + length/2, y2 + length/2, x2 - length/2, y2 + length/2, length);
		shrinking( x1 - length/2, y4 - length/2, x1 + length/2, y4 - length/2, x1 + length/2, y4 + length/2, x1 - length/2, y4 + length/2, length);
		shrinking( x2 - length/2, y3 - length/2, x2 + length/2, y3 - length/2, x2 + length/2, y3 + length/2, x2 - length/2, y3 + length/2, length); 
	}
}

void spiral(double x, double y, double radius, double length, double angle) {
	
	if (radius < 0.05) 
		return;
	else {
		double radiusx = x + radius*cos(angle);
		double radiusy = y + radius*sin(angle);
		drawSquares(radiusx - length/2, radiusy - length/2, radiusx + length/2, radiusy - length/2, radiusx + length/2, radiusy + length/2, radiusx - length/2, radiusy + length/2);
		angle = angle + M_PI/4;
		length = length - 3;
		radius = radius - 20;

		spiral(x, y, radius, length, angle);
	}

}



void drawSquares (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x3, y3, x4, y4);
	gfx_line(x4, y4, x1, y1);
}

void circular(double x, double y, double radius, double angle) {

	if (radius < 1) 
		return;
	else {
		gfx_circle(x, y, radius/2);
		
		circular(x + radius, y, radius/3, 0);
		circular(x + radius*cos(M_PI/3), y + radius*sin(M_PI/3), radius/3, M_PI/3);
		circular(x + radius*cos(2*M_PI/3), y + radius*sin(2*M_PI/3), radius/3, 2*M_PI/3);
		circular(x - radius, y, radius/3, 3*M_PI/3);
		circular(x + radius*cos(4*M_PI/3), y + radius*sin(4*M_PI/3), radius/3, 4*M_PI/3);
		circular(x + radius*cos(5*M_PI/3), y + radius*sin(5*M_PI/3), radius/3, 5*M_PI/3);

	}
}

void snowflake(double x1, double y1, double radius) {

	if (radius < 0.5)
		return;
	else {
		gfx_line(x1, y1, x1 + radius*cos(M_PI/10), y1 + radius*sin(M_PI/10));
		gfx_line(x1, y1, x1, y1 + radius);
		gfx_line(x1, y1, x1 - radius*cos(M_PI/10), y1 + radius*sin(M_PI/10));
		gfx_line(x1, y1, x1 - radius*cos(3*M_PI/10), y1 - radius*sin(3*M_PI/10));
		gfx_line(x1, y1, x1 + radius*cos(3*M_PI/10), y1 - radius*sin(3*M_PI/10));

		snowflake(x1 + radius*cos(M_PI/10), y1 + radius*sin(M_PI/10), radius/4);
		snowflake(x1, y1 + radius, radius/4);
		snowflake(x1 - radius*cos(M_PI/10), y1 + radius*sin(M_PI/10), radius/4);
		snowflake(x1 - radius*cos(3*M_PI/10), y1 - radius*sin(3*M_PI/10), radius/4);
		snowflake(x1 + radius*cos(3*M_PI/10), y1 - radius*sin(3*M_PI/10), radius/4);
	}

}

void tree(double x, double y, double radius, double angle) {

	double x1, y1, x2, y2;
	
	if (radius < 3) 
		return;
	else {			
		double x1 = x + radius*cos(angle);
		double y1 = y - radius*sin(angle);

		gfx_line(x, y, x1, y1);
		
		tree(x1, y1, radius*2/3, angle + M_PI/5);
		tree(x1, y1, radius*2/3, angle - M_PI/5);
	}	
		
}

void ferns(double x, double y, double radius, double angle) {

	if (radius < 3) 
		return;
	else {
		double x1 = x + (radius/3)*cos(angle);
		double y1 = y - (radius/3)*sin(angle);
	
		gfx_line(x, y, x1, y1);
		
		ferns(x1 + (radius/4)*cos(angle), y1 - (radius/4)*sin(angle), radius/3, angle + M_PI/5);
		ferns(x1 + (radius/4)*cos(angle), y1 - (radius/4)*sin(angle), radius/3, angle - M_PI/5);
		ferns(x1 + 2*(radius/4)*cos(angle), y1 - 2*(radius/4)*sin(angle), radius/3, angle + M_PI/5);
		ferns(x1 + 2*(radius/4)*cos(angle), y1 - 2*(radius/4)*sin(angle), radius/3, angle - M_PI/5);
		ferns(x1 + 3*(radius/4)*cos(angle), y1 - 3*(radius/4)*sin(angle), radius/3, angle + M_PI/5);
		ferns(x1 + 3*(radius/4)*cos(angle), y1 - 3*(radius/4)*sin(angle), radius/3, angle - M_PI/5);
		ferns(x1 + 4*(radius/4)*cos(angle), y1 - 4*(radius/4)*sin(angle), radius/3, angle + M_PI/5);
		ferns(x1 + 4*(radius/4)*cos(angle), y1 - 4*(radius/4)*sin(angle), radius/3, angle - M_PI/5);	
	
		gfx_line(x1, y1, x1 + 4*(radius/4)*cos(angle), y1 - 4*(radius/4)*sin(angle));

	}

}

void spiral1(double x, double y, double radius, double angle) {

	if (radius < 0.6)
		return;
	else {
		double x1 = x + radius*cos(angle);
		double y1 = y + radius*sin(angle);
		
		gfx_point(x1, y1);

		spiral1(x1, y1, radius*0.5, angle);

		spiral1(x, y, radius*0.8, angle + M_PI/4);			
	}
}



			



