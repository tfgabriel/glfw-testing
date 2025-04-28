#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

struct col{
  float r;
  float g;
  float b;
  float a;
};

typedef struct col Color;

bool epsEq(float a, float b);

float floatMod(float a, float b);

float floatNorm(float a);

Color colNorm(Color color);

Color mkColor(float r, float g, float b, float a);

Color addColor(Color c1, Color c2);

Color addChScalar(Color color, float x, int type);

#endif
