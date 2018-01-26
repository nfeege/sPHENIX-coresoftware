#ifndef PHParameterContainerInterface__H
#define PHParameterContainerInterface__H

#include <map>
#include <string>

class PHCompositeNode;
class PHParameters;
class PHParametersContainer;

class PHParameterContainerInterface
{
 public:
  PHParameterContainerInterface(const std::string &name);
  virtual ~PHParameterContainerInterface();

  void set_name(const std::string &name);
  virtual void  SetDefaultParameters() = 0;

 // Get/Set parameters from macro
  void set_double_param(const int id, const std::string &name, const double dval);
  double get_double_param(const int id, const std::string &name) const;
  void set_int_param(const int id, const std::string &name, const int ival);
  int get_int_param(const int id, const std::string &name) const;
  void set_string_param(const int id, const std::string &name, const std::string &sval);
  std::string get_string_param(const int id, const std::string &name) const;

  void UpdateParametersWithMacro();
  void CreateInitialize(const int detid);
  void SaveToNodeTree(PHCompositeNode *runNode, const std::string &nodename);
  void PutOnParNode(PHCompositeNode *parNode, const std::string &nodename);
  int ExistDetid(const int detid) const;

 protected:
  void set_default_double_param( const std::string &name, const double dval);
  void set_default_int_param( const std::string &name, const int ival);
  void set_default_string_param( const std::string &name, const std::string &sval);
  void InitializeParameters();
  const PHParametersContainer *GetParamsContainer() {return paramscontainer;}
  PHParametersContainer *GetParamsContainerModify() {return paramscontainer;}
  const PHParameters *GetDefaultParameters() {return defaultparams;}

 private:
  PHParametersContainer *paramscontainer;
  PHParameters *defaultparams;
  std::map<int, PHParameters *> macroparams;
};

#endif
