/*=====================================================================
  functions.hpp   
  Yota INOUE (2021) 
  粒子法プログラムの関数定義ファイル
  Last update: Feb 10, 2021
=======================================================================*/

void initializeParticlePositionAndVelocity_for2dim(void);   // t = 0sでの粒子の速度と位置を決定
void initializeParticlePositionAndVelocity_for3dim(void);
void calConstantParameter(void);
void calNZeroAndLambda(void);
double weight(double distance, double re);
void mainLoopOfSimulation(void);
void calGravity(void);
void calViscosity(void);
void moveParticle(void);
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

