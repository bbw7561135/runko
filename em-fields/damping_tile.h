#pragma once

#include <type_traits>
#include <algorithm>

#include "tile.h"


namespace fields {
  namespace damping {


/* \brief Damping electro-magnetic tile
 *
 */
template<
  std::size_t D,
  int S
>
class Tile : 
  virtual public fields::Tile<D>
{

  public:

  //--------------------------------------------------
  // reference field to relax tile into

  /// Electric field 
  toolbox::Mesh<Realf, 1> ex_ref;
  toolbox::Mesh<Realf, 1> ey_ref;
  toolbox::Mesh<Realf, 1> ez_ref;
  
  /// Magnetic field 
  toolbox::Mesh<Realf, 1> bx_ref;
  toolbox::Mesh<Realf, 1> by_ref;
  toolbox::Mesh<Realf, 1> bz_ref;


  /// constructor
  Tile(size_t nx, size_t ny, size_t nz) :
    fields::Tile<D>(nx,ny,nz),

    ex_ref(nx,ny,nz),
    ey_ref(nx,ny,nz),
    ez_ref(nx,ny,nz),

    bx_ref(nx,ny,nz),
    by_ref(nx,ny,nz),
    bz_ref(nx,ny,nz)
  { }


  ~Tile() override = default;

  //void push_e() override;
  //using Tile::push_e;
  //using Tile::push_half_b;


  //void deposit_current() override;

  //using fields::Tile<D>::dt;
  using fields::Tile<D>::dx;
  using fields::Tile<D>::cfl;


  // damp field 
  void damp_fields();

  /// start index of the slope
  Realf fld1;
    
  /// end index of the slope
  Realf fld2;


};



  } // end on namespace damping
} // end on namespace fields
