void initializeStructures() 
{
  //a struct is similar to an object in an object-oriented language like c#
  //one can initialize and declare a new instance of a struct:
  //struct dataSet dataSetName;
  
  //and set a value to the variables stored in that struct with the syntax:
  //datasetName.key = 123;
  
  //or get data from a struct:
  //int cipherIndex = dataSetName.cipherIndex;
  struct dataSet
  {
    int key;
    char direction;
    int cipherIndex;
  }
}
