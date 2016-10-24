#include "testCommandLineArguments.h"

int main(int argc, char* argv[])
{
  //printing the arguments passed
  //note how the first argument is always the name of the file by default
  //so if you pass 2 arguments, argc is 3
  for(int i=0; i!=argc; i++)
    {
      std::cout<<"arg["<<i<<"]="<<argv[i]<<std::endl;
    }

  //this way you check if the user provided the right number of arguments
  //if not, abort the code in a controlled way using assert
  //which tells you at what line the code crashed
  //the user can safely call your code with no argument
  //then it will crash but tell him first an example of how to use the code
  //let's say we want two arguments

  //it should be the number of inputs plus 1
  if(argc!=3)
    {

      std::cout<<"You ran: ";
      for(int i=0; i!=argc; i++)
	{
	  std::cout<<" "<<argv[i];
	}
      std::cout<<std::endl;      
      std::cout<<"You need 2 arguments, but you passed "<<argc-1<<" arguments. Copy an example from below. Now we ABORT!"<<std::endl;
      std::cout<<"Usage/Example: "
	       <<argv[0]
	       <<" first_argument"
	       <<" second_argument"
	       <<std::endl;
      //crash the code in a controlled way
      assert(false);
    }

  //if you reached here, it means the user provided the correct number
  //of arguments that we desired, so we can proceed to read the arguments
  //example how to read the input arguments of type *char
  //and how to convert them into different types
  //std::string input_file_name(argv[1]);
  //float a=atof(argv[1]);
  //float a=(double)atof(argv[1]);
  //int a=atoi(argv[1]);
  //unsigned a=(unsigned)atoi(argv[1]);
  //bool add_truth=(bool)atoi(argv[1]);

  return 0;
}
