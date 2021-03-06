//----------------------------------*-C++-*----------------------------------------------//
/*!
 * \file   quadrature/Ordinate.hh
 * \author Kent Budge
 * \date   Tue Dec 21 14:20:03 2004
 * \brief  Declaration file for the class rtt_quadrature::Ordinate.
 * \note   Copyright (C)  2016 Los Alamos National Security, LLC.
 *         All rights reserved. 
 */
//---------------------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------------------//

#ifndef quadrature_Ordinate_hh
#define quadrature_Ordinate_hh

#include "ds++/Soft_Equivalence.hh"

namespace rtt_quadrature {
using rtt_dsxx::soft_equiv;

//=======================================================================================//
/*!
 * \class Ordinate
 * \brief Class containing angle cosines and weights for an element of
 * an ordinate set.
 *
 * Provides a container that represents \f$ \mathbf\Omega_m = \mu_m \mathbf e_x +
 * \eta_m \mathbf e_y + \xi_m \mathbf e_z \f$ plus the associated point weight,
 * \f$ w_m \f$. We could represent this as a simple 4-tuple of doubles, but
 * the ordinates must satisfy certain invariants that are protected by the
 * class representation.
 */
//=======================================================================================//

class Ordinate {
public:
  // CREATORS

  //! Create an uninitialized Ordinate.  This is required by the
  //! constructor for vector<Ordinate>.
  Ordinate() : mu_(0), eta_(0), xi_(0), wt_(0) {}

  //! Construct an Ordinate from the specified vector and weight.
  Ordinate(double const mu, double const eta, double const xi, double const wt)
      : mu_(mu), eta_(eta), xi_(xi), wt_(wt) {
    Require(soft_equiv(mu * mu + eta * eta + xi * xi, 1.0));
  }

  //! Construct a 1D Ordinate from the specified angle and weight.
  inline Ordinate(double const mu, double const wt)
      : mu_(mu), eta_(0.0), xi_(0.0), wt_(wt) {
    Require(mu >= -1.0 && mu <= 1.0);
  }

  // Accessors

  double mu() const { return mu_; };
  double eta() const { return eta_; };
  double xi() const { return xi_; };
  double wt() const { return wt_; };

  void set_wt(double const wt) { wt_ = wt; };

  double const *cosines() const {
    // This is a little krufty, but guaranteed to work according to C++
    // object layout rules.
    return &mu_;
  }

private:
  // DATA

  // The data must be kept private in order to protect the norm invariant.

  //! Angle cosines for the ordinate.
  // Do not change the layout of these members! They must be declared in
  // this sequence for cosines() to work as expected!
  double mu_, eta_, xi_;

  //! Quadrature weight for the ordinate.
  double wt_;
};

//---------------------------------------------------------------------------------------//
//! Test ordinates for equality
inline bool operator==(Ordinate const &a, Ordinate const &b) {
  return a.mu() == b.mu() && a.eta() == b.eta() && a.xi() == b.xi() &&
         a.wt() == b.wt();
}

} // end namespace rtt_quadrature

#endif // quadrature_Ordinate_hh

//---------------------------------------------------------------------------------------//
//              end of quadrature/Ordinate.hh
//---------------------------------------------------------------------------------------//
