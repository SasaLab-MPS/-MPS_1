/*=====================================================================
  functions.hpp   
  Yota INOUE (2021) 
  粒子法プログラムの関数定義ファイル
  Last update: Feb 10, 2021
=======================================================================*/
//#include "functions.hpp"
#ifndef FUNCTIONS_HPP_20210211_202753_
#define FUNCTIONS_HPP_20210211_202753_

void initializeParticlePositionAndVelocity_for2dim(void);   // t = 0sでの粒子の速度と位置を決定 (2次元)
void initializeParticlePositionAndVelocity_for3dim(void);   // t = 0sでの粒子の速度と位置を決定 (3次元)
void calConstantParameter(void);
void calNZeroAndLambda(void);               // 初期粒子密度 n0および lambdaの計算
double weight(double distance, double re);  // 重み関数の計算
void mainLoopOfSimulation(void);            // メインループ
void calGravity(void);                      // NS方程式右辺第三項を計算，重力による粒子の加速を計算
void calViscosity(void);                    // NS方程式右辺第二項を計算，粘性による粒子の加速を計算
void moveParticle(void);                    // 粒子の移動を計算
void collision(void);
void calPressure(void);
void calNumberDensity(void);
void setBoundaryCondition(void);
void setSourceTerm(void);
void setMatrix(void);
void exceptionalProcessingForBoundaryCondition(void);
void checkBoundaryCondition(void);
void increaseDiagonalTerm(void);
void solveSimultaniousEquationsByGaussEliminationMethod(void);
void removeNegativePressure(void);
void setMinimumPressure(void);
void calPressureGradient(void);
void moveParticleUsingPressureGradient(void);
void writeData_inProfFormat(void);
void writeData_inVtuFormat(void);

#endif FUNCTIONS_HPP_20210211_202753_