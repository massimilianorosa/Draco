//----------------------------------*-C++-*----------------------------------//
/*!
  \file   Norms_Base.cc
  \author Rob Lowrie
  \date   Fri Jan 14 13:01:37 2005
  \brief  Implemention for Norms_Base class.
  \note   Copyright © 2016 Los Alamos National Security, LLC.  
*/
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#include "Norms_Base.hh"

using namespace rtt_norms;

//---------------------------------------------------------------------------//
/*!
  \brief Default constructor.
*/
//---------------------------------------------------------------------------//
Norms_Base::Norms_Base(void)
    : d_sum_L1(-42.0), d_sum_L2(-42.0), d_Linf(-42.0), d_sum_weights(-42.0) {
  reset();
}
//---------------------------------------------------------------------------//
/*!
  \brief Destructor.
*/
//---------------------------------------------------------------------------//
Norms_Base::~Norms_Base() { /* empty */
}

//---------------------------------------------------------------------------//
/*!
  \brief  Re-initializes the norm values.
*/
//---------------------------------------------------------------------------//
void Norms_Base::reset() {
  d_sum_L1 = 0.0;
  d_sum_L2 = 0.0;
  d_Linf = 0.0;
  d_sum_weights = 0.0;
}
//---------------------------------------------------------------------------//
/*!
  \brief Equality operator.
*/
//---------------------------------------------------------------------------//
bool Norms_Base::operator==(const Norms_Base &n) const {
  return (d_sum_L1 == n.d_sum_L1) && (d_sum_L2 == n.d_sum_L2) &&
         (d_Linf == n.d_Linf) && (d_sum_weights == n.d_sum_weights);
}

//---------------------------------------------------------------------------//
// end of Norms_Base.cc
//---------------------------------------------------------------------------//
