/** z88dk.c
*/
#include <testfwk.h>
#include <stdlib.h>

#if !defined(__SDCC_z80) && !defined(__SDCC_z180) && !defined(__SDCC_r2k) && !defined(__SDCC_r3ka) && !defined(__SDCC_tlcs90)
#define __z88dk_fastcall
#define __z88dk_callee
#endif
#if !defined(__SDCC_z80) && !defined(__SDCC_z180) && !defined(__SDCC_r2k) && !defined(__SDCC_r3ka) && !defined(__SDCC_tlcs90) && !defined(__SDCC_stm8)
#define __smallc
#endif

/* __z88dk_fastcall is supported both on the caller and the callee side */

unsigned char f1(unsigned char c) __z88dk_fastcall
{
	return c + 1;
}

unsigned int f2(unsigned int c) __z88dk_fastcall
{
	return c + 1;
}

#if !defined(__SDCC_hc08) && !defined(__SDCC_s08)
unsigned long int f4(unsigned long int c) __z88dk_fastcall
#else
unsigned long int f4(unsigned long int c) __z88dk_fastcall __reentrant
#endif
{
	return c + 1;
}

unsigned char (*p1)(unsigned char) __z88dk_fastcall;
unsigned int (*p2)(unsigned int) __z88dk_fastcall;
#if !defined(__SDCC_hc08) && !defined(__SDCC_s08)
unsigned long int (*p4)(unsigned long int) __z88dk_fastcall;
#else
unsigned long int (*p4)(unsigned long int) __z88dk_fastcall __reentrant;
#endif

/* __z88dk_callee is currently only supported on the caller side */

void s1(int x, int y) __smallc;

void s2(int x, int y) __z88dk_callee;

void s3(int x, int y) __smallc __z88dk_callee;

void
testZ88dk(void)
{
  ASSERT (f1 (23) == 24);
  ASSERT (f2 (23) == 24);
  ASSERT (f4 (23) == 24);

  p1 = &f1;
  p2 = &f2;
  p4 = &f4;

  ASSERT ((*p1) (23) == 24);
  ASSERT ((*p2) (23) == 24);
  ASSERT ((*p4) (23) == 24);
}

