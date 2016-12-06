#include "SimulatedMemory.h"

int main() {
  // // SimulatedMemory *checkMem;
  for (int i = 1; i < 100; i++) {
    SimulatedMemory checkMem(i);
    // std::cout << checkMem.getAnomaliesDetected() << "|";
  }
  return 0;
}
// Length of memory reference string: 1000
// Frames of physical memory: 100
//
// Anomaly Discovered!
//    Sequence: 18
//    Page Faults: 628 @ Frame Size: 88
//    Page Faults: 631 @ Frame Size: 89
// Anomaly Discovered!
//    Sequence: 22
//    Page Faults: 685 @ Frame Size: 84
//    Page Faults: 688 @ Frame Size: 85
// Anomaly Discovered!
//    Sequence: 23
//    Page Faults: 627 @ Frame Size: 93
//    Page Faults: 628 @ Frame Size: 94
// Anomaly Discovered!
//    Sequence: 36
//    Page Faults: 682 @ Frame Size: 83
//    Page Faults: 683 @ Frame Size: 84
// Anomaly Discovered!
//    Sequence: 41
//    Page Faults: 629 @ Frame Size: 92
//    Page Faults: 631 @ Frame Size: 93
// Anomaly Discovered!
//    Sequence: 67
//    Page Faults: 638 @ Frame Size: 96
//    Page Faults: 640 @ Frame Size: 97
//
// Anomaly detected 6 times.
