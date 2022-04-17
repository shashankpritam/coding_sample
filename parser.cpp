#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main ()
{
  std::ofstream ofs;
  string pdb;
  cout << "Please enter the four letter PDB Code here: ";
  cin >> pdb;
  cout << "The PDB ID you have entered is " << pdb << endl;
  ofs.open("listfile.txt", std::ofstream::out | std::ofstream::trunc);
  ofs << pdb;
  ofs.close();
  string file;
  string add(".pdb.gz");
  file = pdb+add;
  cout << file << endl;
  system("/mnt/d/git/c0d3z4pUblik/batch_download.sh; ./batch_download.sh -f listfile.txt -p &");
  system(("gzip -d < "+file+" > "+pdb+".pdb").c_str());
  return 0;
}
