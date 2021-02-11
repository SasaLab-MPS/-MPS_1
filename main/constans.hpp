/*=====================================================================
  define.hpp   
  Yota INOUE (2021) 

  粒子法プログラムの各定数定義ファイル
  Last update: Feb 10, 2021
=======================================================================*/

#include <bits/stdc++.h>
using namespace std;

#define DIM 2                   // 次元
#define PARTICLE_DISTANCE 0.025 // 初期粒子間距離 l0
#define DT 0.001                // 時間刻み幅
#define OUTPUT_INTERVAL 20      // 計算結果のファイル出力の間隔

/* for three-dimensional simulation */
/*
#define DIM                  3
#define PARTICLE_DISTANCE    0.075
#define DT                   0.003
#define OUTPUT_INTERVAL      2 
*/

#define ARRAY_SIZE 5000 // 粒子数の上限
#define FINISH_TIME 2.0 // シミュレーションの終了時刻
#define KINEMATIC_VISCOSITY (1.0E-6)
#define FLUID_DENSITY 1000.0
#define G_X 0.0
#define G_Y -9.8
#define G_Z 0.0
#define RADIUS_FOR_NUMBER_DENSITY (2.1 * PARTICLE_DISTANCE)
#define RADIUS_FOR_GRADIENT (2.1 * PARTICLE_DISTANCE)
#define RADIUS_FOR_LAPLACIAN (3.1 * PARTICLE_DISTANCE)
#define COLLISION_DISTANCE (0.5 * PARTICLE_DISTANCE)
#define THRESHOLD_RATIO_OF_NUMBER_DENSITY 0.97
#define COEFFICIENT_OF_RESTITUTION 0.2
#define COMPRESSIBILITY (0.45E-9)
#define EPS (0.01 * PARTICLE_DISTANCE)
#define ON 1
#define OFF 0
#define RELAXATION_COEFFICIENT_FOR_PRESSURE 0.2
#define GHOST -1
#define FLUID 0
#define WALL 2
#define DUMMY_WALL 3
#define GHOST_OR_DUMMY -1
#define SURFACE_PARTICLE 1
#define INNER_PARTICLE 0
#define DIRICHLET_BOUNDARY_IS_NOT_CONNECTED 0
#define DIRICHLET_BOUNDARY_IS_CONNECTED 1
#define DIRICHLET_BOUNDARY_IS_CHECKED 2