#ifndef __GLOBALVERTEXFASTSIMRECO_H__
#define __GLOBALVERTEXFASTSIMRECO_H__

//===========================================================
/// \file GlobalVertexFastSimReco.h
/// \brief simple truth vertex smearing algorithm
/// \author Mike McCumber
//===========================================================

#include <fun4all/SubsysReco.h>
// rootcint barfs with this header so we need to hide it
#ifndef __CINT__
#include <gsl/gsl_rng.h>
#endif

class PHCompositeNode;

/// \class GlobalVertexFastSimReco
///
/// \brief simple truth vertex smearing algorithm
///
class GlobalVertexFastSimReco : public SubsysReco {

 public:
 
  GlobalVertexFastSimReco(const std::string &name = "GlobalVertexFastSimReco");
  virtual ~GlobalVertexFastSimReco();
		
  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void set_x_smearing(const float x_smear) {_x_smear = x_smear;}
  void set_y_smearing(const float y_smear) {_y_smear = y_smear;}
  void set_z_smearing(const float z_smear) {_z_smear = z_smear;}
  void set_t_smearing(const float t_smear) {_t_smear = t_smear;}
  
 private:

  int CreateNodes(PHCompositeNode *topNode);

  float _x_smear;
  float _y_smear;
  float _z_smear;
  float _t_smear;
#ifndef __CINT__
  gsl_rng *RandomGenerator;
#endif

};

#endif // __GLOBALVERTEXFASTSIMRECO_H__
