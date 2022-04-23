#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;


int main ()
{
  std::ofstream ofs;
  string pdb;
  cout << "Please enter the four letter PDB Code here: ";
  cin >> pdb;
  cout << "The PDB ID you have entered is " << pdb << endl;
  // Insert PDB ID in listfile.txt - In case there are multiple entries.
  ofs.open("listfile.txt", std::ofstream::out | std::ofstream::trunc);
  ofs << pdb;
  ofs.close();
  string file;
  string add(".pdb.gz");
  file = pdb+add;
  cout << file << endl;
  // Dowload PDB from RCSB
  system("./batch_download.sh -f listfile.txt -p");
  // Decompress to .pdb format
  system(("gzip -d < "+file+" > "+pdb+".pdb").c_str());
  return 0;
}

/*
// Define some terms
class ReadPDB {
public:
  string Atom; // Atom Name
};

// Define Coordinate Structure
struct Coordinates
{
  double x;   // X Coordinate
  double y;  // Y Coordinate
  double z;   // Z Coordinate
};

// Create "is" having Coordinates
std::istream& operator>>(std::istream& is, Coordinates& coordinates){
  is >> coordinates.x >> coordinates.y >> coordinates.z;
  return is;
}

// Try printing the data
void PrintData(){
  string ext(".pdb");
  pdb_file = pdb_id+ext;
  std::ifstream ifs(pdb_file);
  // Now you can work with the contents of v
}
*/


// Some Comments
