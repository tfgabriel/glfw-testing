#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "util.h"

bool epsEq(float a, float b){
  return fabs(a-b) < 0.00001f;
}

float floatMod(float a, float b){
  return a - (int32_t)(a/b) * b;
}

float floatNorm(float a){
  return floatMod(a, 1.0f);
}

Color colNorm(Color color){
  return (Color){ floatNorm(color.r), floatNorm(color.g), floatNorm(color.b), color.a};
}

Color mkColor(float r, float g, float b, float a){
  Color col = {.r = r, .g = g, .b = b, .a = a};
  return colNorm(col);
}

Color addColor(Color c1, Color c2){
  return mkColor(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b, c1.a + c2.a);
}

Color addChScalar(Color color, float x, int type){
  Color col = { .r = color.r, .g = color.g, .b = color.b, .a = color.a};
  switch(type){
    case 1:
      col.r += x;
      break;
    case 2:
      col.g += x;
      break;
    case 3:
      col.b += x;
      break;
    default:
  }

  return colNorm(col);
}

