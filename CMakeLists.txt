cmake_minimum_required (VERSION 3.8)

project (Almag_RetDriver)
message(status "AlmagRetDriver MainCMakeLists")

find_package(Boost 1.71.0 REQUIRED COMPONENTS log date_time)

# options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") # create debug symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe") # optimize hardware usage during compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # for using threads
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finline-functions") # helps considering about inlining functions
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -freorder-blocks") # helps compiler with compilation

# warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic") # warning if violates ISO standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors") # error if violates ISO standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # enables all compiler's warning messages
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # enables extra compiler's warning messages
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Woverloaded-virtual")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor")

# size optimizations flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--sort-common") # sort symbols by size
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--gc-sections") # enable gc of unused input sections
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections") # remove unused data/functions during linking time

# suppresses
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter") # disables warning about unused parameter 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-lstdc++fs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lzmq")

message("** Boost Include: ${Boost_INCLUDE_DIR}")
message("** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message("** Boost Libraries: ${Boost_LIBRARIES}")

# BINARY BOTH
include_directories(${Boost_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(${Boost_LIBRARY_DIRS})
add_definitions( -DBOOST_ALL_DYN_LINK)

# External libraries
include_directories(${PROJECT_SOURCE_DIR}/externalLibraries)

set(DATABASE
    ${PROJECT_SOURCE_DIR}/externalLibraries/Database/Database.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Database/Database.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Database/Objects/IOPaths.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Database/Objects/IOPaths.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Database/Utils/KeyWithValue.hpp
)

set(COMMAND_PATTERN
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/AlmagController.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/AlmagController.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/AlmagControllerNull.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/AlmagControllerNull.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/IController.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/AISGProtocolVersion.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/AISGProtocolVersion.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/AddressAssignment.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/AddressAssignment.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/Calibrate.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/Calibrate.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/DummyScan.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/DummyScan.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/DeviceScan.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/DeviceScan.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/HDLCParameters.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/HDLCParameters.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/ICommand.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/ICommand.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/HDLCCommand.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/HDLCCommand.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/IHDLCFrameBodyFactory.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/ICommandFactory.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/LinkEstablishment.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/LinkEstablishment.hpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/ThreeGPPReleaseID.cpp
    ${PROJECT_SOURCE_DIR}/src/CommandPattern/Commands/ThreeGPPReleaseID.hpp
)

set(HDLC
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameBase.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameBase.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrame.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrame.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCParametersValues.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCParametersValues.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrameBody.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrameBody.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/IHDLCCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/MessagesHelpers.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/MessagesHelpers.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrameBodyInterpreter.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCFrameBodyInterpreter.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCRespFrameBodyFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/HDLCRespFrameBodyFactory.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameI.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameI.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameU.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameU.hpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameXID.cpp
    ${PROJECT_SOURCE_DIR}/src/HDLC/FrameTypes/FrameXID.hpp
)

set(LOGGER
    ${PROJECT_SOURCE_DIR}/src/Utils/Logger.cpp
    ${PROJECT_SOURCE_DIR}/src/Utils/Logger.hpp
)

set(UTILS
    ${PROJECT_SOURCE_DIR}/src/Utils/UserCommandParser.cpp
    ${PROJECT_SOURCE_DIR}/src/Utils/UserCommandParser.hpp
)

set(EXTERNAL_LIBRARIES_UTILS
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/Utils.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/Utils.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/TypeAliases.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/Functions.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/Functions.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/PrintUtils.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/Utils/PrintUtils.hpp
)

set(PLUGIN_SPECIFICS
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/CmdConstraints/AlmagConstraints.hpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/CmdConstraints/DatabaseConstraints.hpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.cpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/RetDriverCommandFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/RetDriverCommandFactory.hpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/HDLCReqFrameBodyFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/PluginSpecifics/HDLCReqFrameBodyFactory.hpp
)

set(USER_INTERFACE
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CMenu.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CMenu.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/Database/CDatabaseCommand.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/Database/CDatabaseCommand.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/Database/Brokers/Broker_IOPaths.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/Database/Brokers/Broker_IOPaths.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/DummyScanValidationStrategy.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/DummyScanValidationStrategy.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/ICmdValidationManager.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/ICommandValidationStrategy.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/ICommandValidationStrategy.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/NullValidationStrategy.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/UserInterface/CtrlCommandsValidators/NullValidationStrategy.hpp
)

add_subdirectory(3rdparty/googletest/googlemock)
add_subdirectory(test)
add_subdirectory(src)

