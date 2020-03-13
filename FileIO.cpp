#include "FileIO.h"
#include <fstream>
#include <string>
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life


FileIO::FileIO()
{
  //default constructor
}


FileIO::~FileIO()
{
  //deconstructor
}

//mapping data in order to print to txt file
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

//prints out generations to txt file
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
