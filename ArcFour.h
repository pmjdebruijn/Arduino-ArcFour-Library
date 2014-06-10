/*
  ArcFour.h
  
  created 10 Jun 2014
  by Pascal de Bruijn
  
 */

#ifndef ArcFour_h
#define ArcFour_h

#include <inttypes.h>

#define ARCFOUR_MAX 256

class ArcFour
{
  uint8_t _i;
  uint8_t _j;
  uint8_t _s[ARCFOUR_MAX];
public:
  void initialize(void);
  void seed(uint8_t index, uint8_t key);
  void finalize(void);
  uint8_t random(void);
private:
  void swap(uint8_t *a, uint8_t *b);
};

#endif

