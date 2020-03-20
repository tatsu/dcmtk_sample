#include <iostream>
#include <dcmtk/dcmdata/dctk.h>

using namespace std;

int main() {
  DcmFileFormat fileFormat;
  OFCondition status = fileFormat.loadFile("../CT_small.dcm");
  if (status.good()) {
    OFString patientName;
    if (fileFormat.getDataset()->findAndGetOFString(DCM_PatientName, patientName).good()) {
      cout << "Patient's Name: " << patientName << endl;
    } else
      cerr << "Error: cannot access Patient's Name!" << endl;
  } else {
    cerr << "Error: cannot read DICOM file (" << status.text() << ")" << endl;
  }

  return 0;
}
