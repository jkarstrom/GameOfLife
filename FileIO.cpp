#include "FileIO.h"
#include <fstream>
#include <string>

FileIO::FileIO()
{
  //default constructor
}


FileIO::~FileIO()
{

}

void FileIO::readMapping(string fileName, Grid *someGrid){
    int rowIdx = 0;
    int columnIdx = 0;
    int rowTotal = someGrid->getRows();
    int columnTotal = someGrid->getColumns();
    string line;
    ifstream inputFile(fileName);
    if(inputFile.is_open()){
        //read line by line
        while(getline(inputFile,line)){
            for(int i = 0; i < (line.length()-1); ++i){
                someGrid->setCell(rowIdx, columnIdx, line[i]);
                ++columnIdx;
                if(columnIdx == columnTotal){
                    columnIdx = 0;
                    ++rowIdx;
                    if(rowIdx == rowTotal){
                        break;
                    }
                }
            }
        }
        inputFile.close();
    }
}

void FileIO::print(string fileName, Grid *someGrid)
{

  ofstream outputFile;
  outputFile.open(fileName,ios::app);
  outputFile << "Generation: " << someGrid->getGenerationNum() << endl;
  for(int r = 0; r < someGrid->getRows(); ++r){
      for(int c = 0; c < someGrid->getColumns(); ++c){
          outputFile << someGrid->getCell(r,c);
      }
      outputFile << endl;
  }
  outputFile << endl;
  outputFile.close();
}
