#include "SimulatedMemory.h"
#include <time.h>

SimulatedMemory::SimulatedMemory(int sqc) {
  fifoSimulation = 1;
  numAnomaliesInSequence = 0;
  sequence = sqc;
  std::srand(time(NULL) + 1);
  createRandomString();
  for (int i = 0; i < 251; i++) {
    Pages[i] = 9999;
    faultsMemSize[100000];
  }
  int num;
  std::cin >> num;
  for (int i = 1; i <= num; i++) {
    pageFaults = 0;
    memorySize = i;
    runThroughMemory();
  }
  numAnomaliesInSequence = 0;
  std::cout << std::endl;
  for (int i = 1; i < num; i++) {
    if (faultsMemSize[i] < faultsMemSize[i + 1]) {
      numAnomaliesInSequence++;
      std::cout << i << "@ ";
      std::cout << faultsMemSize[i] << " | " << faultsMemSize[i + 1]
                << std::endl;
    }
  }
  std::cout << std::endl << "(" << numAnomaliesInSequence << std::endl;
}

SimulatedMemory::~SimulatedMemory() {}

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
  std::cout << "," << pageFaults;
  if (memorySize % 20 == 0) {
    std::cout << std::endl;
  }
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
