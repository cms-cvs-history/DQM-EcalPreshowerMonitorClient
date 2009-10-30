import FWCore.ParameterSet.Config as cms

ecalPreshowerLocalMonitorClient = cms.EDAnalyzer('EcalPreshowerMonitorClient',	
                                            LookupTable = cms.untracked.FileInPath('EventFilter/ESDigiToRaw/data/ES_lookup_table.dat'),
                                            OutputFile = cms.untracked.string(''),
                                            InputFile = cms.untracked.string(''),
                                            enableCleanup = cms.untracked.bool(False),
                                            enableMonitorDaemon = cms.untracked.bool(False),
                                            enabledClients = cms.untracked.vstring('Pedestal'),
                                            prefixME = cms.untracked.string('EcalPreshower'),
                                            clientName = cms.untracked.string('EcalPreshowerMonitorClient'),
                                            hostName = cms.untracked.string('localhost'),
                                            hostPort = cms.untracked.int32(9090),
                                            prescaleFactor = cms.untracked.int32(1),
                                            verbose = cms.untracked.bool(True),
                                            debug = cms.untracked.bool(True),
                                            fitPedestal = cms.untracked.bool(False)
                                            )