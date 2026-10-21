#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class FileManager {
  private:
 ofstream file;
 string fileNames = "Unknown";
  public:

FileManager(string fileName)
: file(fileName){
  fileNames = fileName;
  cout << "Opening file : " << fileName << "\n";
}

void write(const string& writInp){
file << writInp << "\n";
}

~FileManager(){
  cout << "Closed file: " << fileNames << "\n";
}
};

void saveData(const string& fileSave){
  FileManager filemanager(fileSave);
  filemanager.write("Beginning to save...");
  return;
}

void riskyOP(const string& riskString) {
  FileManager riskyFile(riskString);
  riskyFile.write("Starting Risky Operation");
  throw runtime_error("Something Went Wrong!");
}

void fileProcess(const string& filePro, bool returnEarly){
  FileManager process(filePro);
  process.write("Started processing.");
  if(returnEarly){
    return;
  }
    process.write("Processing Finished.");
}
class Connection 
{
  private:
  bool conOpen = false;
  public:
  Connection()
  {
   conOpen = true;
   cout << "Connection open! \n";
  }
  ~Connection(){
   cout << "Disconnected \n";
  }
  bool getConOpen(){
   return conOpen;
  }
  void send(){
  if(getConOpen()){
   cout << "Sending data... \n";
  }
  else{
    cout << "Error no connection established \n";
      }
  } 
};

int main()
{
  {
   cout << "Starting program \n";
   Connection connection;
   cout << "Using active connection \n";
   connection.send();
   connection.send();
   FileManager file("notes.txt");
   fileProcess("fruits.txt", false);
   file.write("Learning RAII!");
   saveData("candy.txt");
   try{
     riskyOP("quiet.txt");
      }
      catch(const runtime_error& error){
        cout << error.what() << "\n";
      }
       fileProcess("animals.txt", true);
  }
  cout << "Connection scope ended. \n";
  return 0;
}
