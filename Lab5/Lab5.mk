##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab5
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/jkeho/Documents/APSC143
ProjectPath            :=C:/Users/jkeho/Documents/APSC143/Lab5
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jkeho
Date                   :=04/10/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Lab5.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/enigma.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/enigma.c$(ObjectSuffix): enigma.c $(IntermediateDirectory)/enigma.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/jkeho/Documents/APSC143/Lab5/enigma.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/enigma.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/enigma.c$(DependSuffix): enigma.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/enigma.c$(ObjectSuffix) -MF$(IntermediateDirectory)/enigma.c$(DependSuffix) -MM enigma.c

$(IntermediateDirectory)/enigma.c$(PreprocessSuffix): enigma.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/enigma.c$(PreprocessSuffix) enigma.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


