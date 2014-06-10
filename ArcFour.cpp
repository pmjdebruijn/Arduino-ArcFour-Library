/*
  ArcFour.cpp
  
  created 10 Jun 2014
  by Pascal de Bruijn
  
 */

#include "ArcFour.h"

void ArcFour::initialize(void)
{
  for (int i = 0; i < sizeof(_s); i++)
  {
    _s[i] = i;
  }
  
  _i = 0;
  _j = 0;
}

void ArcFour::seed(uint8_t index, uint8_t key)
{
  _j = (_j + _s[index] + key) % sizeof(_s);
  
  swap(&_s[index], &_s[_j]);
}

void ArcFour::finalize(void)
{
  _i = 0;
  _j = 0;
}

uint8_t ArcFour::random(void)
{
  _i = (_i + 1)      % sizeof(_s);
  _j = (_j + _s[_i]) % sizeof(_s);
  
  swap(&_s[_i], &_s[_j]);
  
  return _s[( _s[_i] + _s[_j]) % sizeof(_s)];
}

void ArcFour::swap(uint8_t *a, uint8_t *b)
{
  uint8_t c;
  
   c = *a;
  *a = *b;
  *b =  c;
}

