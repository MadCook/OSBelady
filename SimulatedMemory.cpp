#include "SimulatedMemory.h"
#include <time.h>

SimulatedMemory::SimulatedMemory(int sqc) {
  fifoSimulation = 1;
  numAnomaliesInSequence = 0;
  sequence = sqc;
  anomalyDetected = false;
  std::srand(time(NULL) + sqc);
  for (int i = 0; i < 100; i++) {
    faultsMemSize[i] = 0;
  }
  createRandomString();
  clearMemory();
  for (int i = 1; i < 99; i++) {
    memorySize = i;
    runThroughMemory();
    clearMemory();
  }
  anomaliesDetected();
}

SimulatedMemory::~SimulatedMemory() {}

void SimulatedMemory::anomaliesDetected() {
  numAnomaliesInSequence = 0;
  for (int i = 1; i < 99; i++) {
    if (faultsMemSize[i] < faultsMemSize[i + 1]) {
      if (!anomalyDetected) {
        std::cout << "Anomaly Discovered!" << std::endl;
        std::cout << "     Sequence:" << sequence << std::endl;
        anomalyDetected = true;
      }
      numAnomaliesInSequence++;
      std::cout << "     Page Faults: " << faultsMemSize[i]
                << " @ Frame Size:" << i << std::endl;
      std::cout << "     Page Faults: " << faultsMemSize[i + 1]
                << " @ Frame Size:" << i + 1 << std::endl;
      fifoSimulation++;
    }
  }
}

void SimulatedMemory::clearMemory() {
  pageFaults = 0;
  for (int i = 0; i < 251; i++) {
    Pages[i] = 9999;
  }
}

void SimulatedMemory::createRandomString() {
  for (int i = 0; i < 1000; i++) {
    rngInts[i] = (std::rand() % 250);
  }
}

void SimulatedMemory::runThroughMemory() {
  currentMemory = new int[memorySize];
  for (int i = 0; i < 1000; i++) {
    int memoryWantingAttention = rngInts[i];
    if (!checkIfInMemory(memoryWantingAttention)) {
      switchPageIntoMemory(memoryWantingAttention);
    }
  }
  faultsMemSize[memorySize] = pageFaults;
  delete[] currentMemory;
}

bool SimulatedMemory::checkIfInMemory(int memoryWantingAttention) {
  int lastKnownLocation = Pages[memoryWantingAttention];
  if (currentMemory[lastKnownLocation] == memoryWantingAttention) {
    return true;
  }
  return false;
}

void SimulatedMemory::switchPageIntoMemory(int memoryWantingAttention) {
  Pages[memoryWantingAttention] = fifoSimulation % memorySize;
  currentMemory[fifoSimulation % memorySize] = memoryWantingAttention;
  pageFaults++;
  fifoSimulation++;
}

int SimulatedMemory::getAnomaliesDetected() { return numAnomaliesInSequence; }
