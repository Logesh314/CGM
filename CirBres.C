
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
void plotPoints(int cx, int cy, int x, int y) {
        putpixel(cx+x, cy+y, RED);
        putpixel(cx-x, cy+y, RED);
        putpixel(cx+x, cy-y, RED);
        putpixel(cx-x, cy-y, RED);
        putpixel(cx+y, cy+x, RED);
        putpixel(cx-y, cy+x, RED);
        putpixel(cx+y, cy-x, RED);
        putpixel(cx-y, cy-x, RED);
}
void main() {
        int cx, cy, x = 0, y, r, p;
        int gd = DETECT, gm;
        clrscr();
        printf("Enter the coordinates of centre of the circle: ");
        scanf("%d %d", &cx, &cy);
        printf("Enter radius of : ");
        scanf("%d", &r);
        y = r;
        p = 3 - 2 * r;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
        cleardevice();
        while (x < y) {
                plotPoints(cx, cy, x, y);
                x++;
                if (p < 0)
			p = p + 4 * x + 6;
		else {
                        y--;
                        p = p + 4 * (x - y) + 10;
                }
                plotPoints(cx, cy, x, y);
		delay(5);
        }
        getch();
}