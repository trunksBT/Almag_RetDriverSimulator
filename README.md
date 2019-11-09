# Almag_RetDriver
UNBLOCKED_SCENARIOS > QUALITY  
SOME SMELLS > OVER-ENGINEERING  
PLANNED REFACTOR AFTER FINISH  

# UML_ActivityDiagram:  
1. Install the https://code.visualstudio.com/download  
2. Install the https://marketplace.visualstudio.com/items?itemName=jebbs.plantuml  
3. Open the docs/UML_DiagramOfSequence.wsd via Visual Studio Code  
4. Click "Alt + D"  

# UML_ClassDiagram:  
1. Install the https://www.microsoft.com/pl-PL/download/details.aspx?id=51188  
2. Open the docs/UML_DiagramOfClasses.vsdx via Visio Viewer  

# Dependencies:
- cmake 3.12.4
- g++ 8.2.1 
- gcc 8.2.1
- libboost-all-dev 1.65

# How to run:  
1.  
- cmake .  
OR
- cmake -DCMAKE_CXX_COMPILER="/usr/bin/g++-8" .
OR
- cmake -DCMAKE_CXX_COMPILER="/usr/bin/g++" .
OR
- cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo // for using gdb
OR  
- make -j4 Almag_RetDriver && ./src/Almag_RetDriver  
  
# How to run tests:  
- make -j4 Almag_RetDriver_MT && ./test/MT/Almag_RetDriver_MT  
- make -j4 Almag_RetDriver_UT && ./test/UT/Almag_RetDriver_UT  

# Logger:  
<Hour:Minute:Second.Milisec> severity [FileName::FunctionName:Line]  

FileName != ClassName

