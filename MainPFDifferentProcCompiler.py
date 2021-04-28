import os
import time

processorsCountFromCPPFile = 120
processorFirst = 7
processorsLast = 8


for thisProcessorNumber in range (processorFirst, processorsLast):
    fin = open("MainProcessFile.cpp", "rt")
    fout = open("MainProcessFileForPy.cpp", "wt")
    for line in fin:
        if line.startswith('constexpr int processorsCount =') and not(line.startswith('constexpr int processorsCount = ' + str(processorsCountFromCPPFile))):
            print("processorsCounts are not equal!")
        if line.startswith('constexpr int thisProcessorNumber =') :
            fout.write('constexpr int thisProcessorNumber = ' + str(thisProcessorNumber) + '; //which lines will this code process')
        else :
            fout.write(line)
    fin.close()
    fout.close()
    command = "g++ -static -O3 ./MainProcessFileForPy.cpp ./prog/*.cpp ./prog/ColoringGenerators/*.cpp ./prog/PathGenerators/*.cpp -o MainProcessFileExes/length10/MainProcessFileProc" + str(thisProcessorNumber) + "of" + str(processorsCountFromCPPFile) + ".exe"
    print("compiling " + str(thisProcessorNumber) + " of " + str(processorsLast-1))
    os.system(command)


