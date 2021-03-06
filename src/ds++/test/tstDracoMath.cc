//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   ds++/test/tstDracoMath.cc
 * \author Kent G. Budge
 * \date   Wed Nov 10 09:35:09 2010
 * \brief  Test functions defined in ds++/draco_math.hh.
 * \note   Copyright (C) 2016 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#include "ds++/DracoMath.hh"
#include "ds++/Release.hh"
#include "ds++/ScalarUnitTest.hh"
#include "ds++/Soft_Equivalence.hh"

//---------------------------------------------------------------------------//
// TESTS
//---------------------------------------------------------------------------//

void tstabs(rtt_dsxx::UnitTest &ut) {
  using rtt_dsxx::abs;

  if (abs(-2.2) == abs(2.2))
    PASSMSG("Correctly calculated abs(double)");
  else
    FAILMSG("Did NOT correctly calculate abs(double)");
  if (abs(-2.2f) == abs(2.2f))
    PASSMSG("Correctly calculated abs(float)");
  else
    FAILMSG("Did NOT correctly calculate abs(float)");
  if (abs(-2) == abs(2))
    PASSMSG("Correctly calculated abs(int)");
  else
    FAILMSG("Did NOT correctly calculate abs(int)");
  if (abs(-2L) == abs(2L))
    PASSMSG("Correctly calculated abs(long)");
  else
    FAILMSG("Did NOT correctly calculate abs(long)");
  return;
}

//---------------------------------------------------------------------------//
void tstconj(rtt_dsxx::UnitTest &ut) {
  if (rtt_dsxx::soft_equiv(rtt_dsxx::conj(3.5), 3.5))
    PASSMSG("conj(double) is correct");
  else
    FAILMSG("conj(double) is NOT correct");

  std::complex<double> c(2.7, -1.4);
  if (rtt_dsxx::soft_equiv((rtt_dsxx::conj(c) * c).real(),
                           rtt_dsxx::square(abs(c))))
    PASSMSG("conj(std::complex) is correct");
  else
    FAILMSG("conj(std::complex) is NOT correct");
  return;
}

//---------------------------------------------------------------------------//
void tstcube(rtt_dsxx::UnitTest &ut) {
  if (rtt_dsxx::soft_equiv(rtt_dsxx::cube(2.0), 8.0))
    PASSMSG("rtt_dsxx::square function returned correct double");
  else
    FAILMSG("rtt_dsxx::square function did NOT return correct double.");
  return;
}

//---------------------------------------------------------------------------//
void tstpythag(rtt_dsxx::UnitTest &ut) {
  using rtt_dsxx::pythag;
  if (rtt_dsxx::soft_equiv(pythag(3.0e307, 4.0e307), 5.0e307))
    PASSMSG("pythag correct");
  else
    FAILMSG("pythag NOT correct");
  if (rtt_dsxx::soft_equiv(pythag(4.0e307, 3.0e307), 5.0e307))
    PASSMSG("pythag correct");
  else
    FAILMSG("pythag NOT correct");
  if (rtt_dsxx::soft_equiv(pythag(0.0, 0.0), 0.0))
    PASSMSG("pythag correct");
  else
    FAILMSG("pythag NOT correct");
  return;
}

//---------------------------------------------------------------------------//
void tstsign(rtt_dsxx::UnitTest &ut) {
  using rtt_dsxx::sign;
  if (sign(3.2, 5.6) != 3.2)
    FAILMSG("sign: FAILED");
  else
    PASSMSG("sign: passed");
  if (sign(4.1, -0.3) != -4.1)
    FAILMSG("sign: FAILED");
  else
    PASSMSG("sign: passed");
  return;
}

//---------------------------------------------------------------------------//
void tstsquare(rtt_dsxx::UnitTest &ut) {
  if (rtt_dsxx::soft_equiv(rtt_dsxx::square(3.0), 9.0))
    PASSMSG("square function returned correct double");
  else
    FAILMSG("square function did NOT return correct double.");
  return;
}

//---------------------------------------------------------------------------//
void test_linear_interpolate(rtt_dsxx::UnitTest &ut) {
  // function y = 2.5 * x - 1.0

  // define boundary points
  double x1 = 1.0;
  double y1 = 2.5 * x1 - 1.0;
  double x2 = 3.0;
  double y2 = 2.5 * x2 - 1.0;

  double x = 1.452;
  double y = rtt_dsxx::linear_interpolate(x1, x2, y1, y2, x);
  double ref = 2.5 * x - 1.0;

  if (!rtt_dsxx::soft_equiv(y, ref))
    ITFAILS;

  // try another one
  x1 = 1.45;
  y1 = 2.5 * x1 - 1.0;
  x2 = 1.1;
  y2 = 2.5 * x2 - 1.0;

  x = 1.33;
  y = rtt_dsxx::linear_interpolate(x1, x2, y1, y2, x);
  ref = 2.5 * x - 1.0;

  if (!rtt_dsxx::soft_equiv(y, ref))
    ITFAILS;

  if (ut.numFails == 0)
    PASSMSG("Linear interpolation checks ok.");
  else
    FAILMSG("test_interpolate() tests fail.");
  return;
}

//---------------------------------------------------------------------------//
int main(int argc, char *argv[]) {
  rtt_dsxx::ScalarUnitTest ut(argc, argv, rtt_dsxx::release);
  try {
    tstabs(ut);
    tstconj(ut);
    tstcube(ut);
    tstpythag(ut);
    tstsign(ut);
    tstsquare(ut);
    test_linear_interpolate(ut);
  }
  UT_EPILOG(ut);
}

//---------------------------------------------------------------------------//
// end of tstDracoMath.cc
//---------------------------------------------------------------------------//
