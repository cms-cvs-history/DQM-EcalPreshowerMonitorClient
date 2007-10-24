#ifndef ESPEDESTALCMTBCLIENT_H
#define ESPEDESTALCMTBCLIENT_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <DataFormats/Common/interface/Handle.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Core/interface/MonitorElementBaseT.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace edm;
using namespace std;

class ESPedestalCMTBClient: public EDAnalyzer{

 public:
  
  ESPedestalCMTBClient(const ParameterSet& ps);
  virtual ~ESPedestalCMTBClient();
  
 protected:
  
  void beginJob(const EventSetup& c);
  void analyze(const Event& e, const EventSetup& c);
  void endJob();
  void setup();
  void cleanup();
  void doQT();

  string getMEName(const int & plane, const int & col, const int & row, const int & strip, const int & slot, const int & type);
  void htmlOutput(int run, string htmlDir, string htmlName);

 private:
  
  bool writeHisto_;
  bool writeHTML_;
  int dumpRate_;
  string outputFile_;
  string outputFileName_;
  string rootFolder_;
  string htmlDir_;
  string htmlName_;
  double cmnThreshold_;
  bool sta_;
  int count_;
  int run_;
  bool init_;
  int gain_;

  DaqMonitorBEInterface* dbe_;

  MonitorElement* meMean_[3];
  MonitorElement* meRMS_[3];
  MonitorElement* meCMCol_[2][3];

  TH1F* hADC_[2][3];
  TH1F* hADCZS_[2][3];
  TH2F* hOCC_[2][3];
};

#endif

