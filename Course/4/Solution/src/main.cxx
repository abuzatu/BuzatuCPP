#include "main.h"

//the main method
int main (int argc, char* argv[]) {
  //if not two arguments, crash in a contol way and tell the people how to run, an example
  if (argc!=7) {
    std::cout<<"Use four arguments:"<<std::endl;
    std::cout<<"./bin/main.exe InputFile         TimeStepInSeconds TotalDurationInEarthYears Extension  Info Debug"<<std::endl;
    std::cout<<"./bin/main.exe ./input/input.txt 86400             1.2                       csv        1    0"<<std::endl;
    std::cout<<"./bin/main.exe ./input/input.txt 86400             1.2                       txt        1    0"<<std::endl;
    assert(false);
    }
  std::string inputfilename=argv[1];//from char* to std::string
  float TimeStepInSeconds=atof(argv[2]);//from char* to float
  float TotalDurationInEarthYears=atof(argv[3]);//from char* to float
  std::string extension=argv[4];//from char* to std::string
  bool info=(bool)atoi(argv[5]);//from int to bool
  bool debug=(bool)atoi(argv[6]);//from int to bool

  //create the system as contructor that takes as input the inputfile
  System system(inputfilename,info,debug);
  //create the outputfiles
  Output output(system,extension,info,debug);

  //fill the status of the system to the output files
  output.Fill(system);
  //loop over the steps and for each step
  unsigned NrSteps=getNrSteps(TimeStepInSeconds,TotalDurationInEarthYears);
  for(unsigned i=0; i!=NrSteps; i++) {
    if(info && i%10000==0) {
      std::cout<<"We are at step "<<i<<std::endl;
    }
    //evolve the system
    system.Evolve(TimeStepInSeconds);
    //fill the status of the system to the output files
    if(i%(60*24)==0)
      output.Fill(system);
  }//done loop over the stps
  //close the files
  output.Close(system);

  //all done ready to exit the main function
  return 0;
}//end if main

unsigned getNrSteps(float TimeStepInSeconds, float TotalDurationInEarthYears) {
  //compute how many steps to let our system evolve
  unsigned NrSteps=(unsigned)(TotalDurationInEarthYears*365*86400/TimeStepInSeconds);
  std::cout<<"We let the system evolve for a total duration of "<<TotalDurationInEarthYears<<" Earth years, with an individual step of "<<TimeStepInSeconds<<" seconds, leading to a total of "<<NrSteps<<" steps."<<std::endl;
  return NrSteps;
}
