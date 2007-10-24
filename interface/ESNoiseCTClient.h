#ifndef ESNOISECTCLIENT_H
#define ESNOISECTCLIENT_H

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

#include "TF1.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace edm;
using namespace std;

class ESNoiseCTClient: public EDAnalyzer{

 public:
  
  ESNoiseCTClient(const ParameterSet& ps);
  virtual ~ESNoiseCTClient();
  
 protected:
  
  void beginJob(const EventSetup& c);
  void analyze(const Event& e, const EventSetup& c);
  void endJob();
  void setup();
  void cleanup();
  void doQT();

  string getMEName(const int & zside, const int & plane, const int & row, const int & col);
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
  int count_;
  int run_;
  bool init_;
  bool sta_;
  TF1 *fg;

  DaqMonitorBEInterface* dbe_;

};

#endif

