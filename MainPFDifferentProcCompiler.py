import os
import time

processorsCountFromCPPFile = 4
lengthOfPath = 11
processorFirst = 0
processorsLast = 4


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
    command = "g++ -static -O3 ./MainProcessFileForPy.cpp ./prog/*.cpp ./prog/ColoringGenerators/*.cpp ./prog/PathGenerators/*.cpp -o MainProcessFileExes/length" + str(lengthOfPath) + "/MainProcessFileProc" + str(thisProcessorNumber) + "of" + str(processorsCountFromCPPFile) + ".exe"
    print("compiling " + str(thisProcessorNumber) + " of " + str(processorsLast-1))
    os.system(command)


