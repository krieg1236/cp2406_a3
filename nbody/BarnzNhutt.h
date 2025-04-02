// BarnzNhutt.h with the function declarations for BarnzNhutt.cpp
#ifndef BARNZNHUTT_H
#define BARNZNHUTT_H

#include "Bhtree.cpp"  // Include your required headers

// Function declarations
void initializeBodies(struct body *bods);
void runSimulation(struct body *b, char *image, double *hdImage);
void interactBodies(struct body *bods);
void singleInteraction(struct body *a, struct body *b);
double magnitude(const vec3 &v);
void updateBodies(struct body *bods);
void createFrame(char *image, double *hdImage, struct body *b, int step);
double toPixelSpace(double p, int size);
void renderClear(char *image, double *hdImage);
void renderBodies(struct body *b, double *hdImage);
void colorDot(double x, double y, double vMag, double *hdImage);
void colorAt(int x, int y, const struct color &c, double f, double *hdImage);
unsigned char colorDepth(unsigned char x, unsigned char p, double f);
double clamp(double x);
void writeRender(char *data, double *hdImage, int step);

#endif // BARNZNHUTT_H
