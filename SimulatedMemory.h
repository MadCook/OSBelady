#ifndef SIMULATEDMEMORY_H
#define SIMULATEDMEMORY_H

#include <array>
#include <iostream>

class SimulatedMemory {
  std::array<int, 251> Pages;
  int fifoSimulation;
  int *currentMemory;
  std::array<int, 1000> rngInts;
  int numAnomaliesInSequence;
  int pageFaults;
  int sequence;
  int memorySize;
  std::array<int, 100> faultsMemSize;

  void createRandomString();
  void runThroughMemory();
  bool checkIfInMemory(int memoryWantingAttention);
  void switchPageIntoMemory(int memoryWantingAttention);

public:
  SimulatedMemory(int sequence);
  ~SimulatedMemory();
  int getAnomaliesDetected();
};

#endif
