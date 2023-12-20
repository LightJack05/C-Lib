sourceFiles := genericLinkedList.c queue.c safeGet.c main.c
buildDirectory := bin
cStandard := c11
defaultOptions := -std=$(cStandard) -fdiagnostics-color=always -Wall -pg -g
programName := main
compiler := gcc
SHELL := /bin/bash

linux:
	if [[ ! -d $(buildDirectory) ]]; then mkdir $(buildDirectory); fi
	$(compiler) $(defaultOptions) $(sourceFiles) -o $(buildDirectory)/$(programName) -lm

windows:
	powershell -c "if (-not (Test-Path -Path $(buildDirectory))) {mkdir bin}"
	$(compiler) $(defaultOptions) $(sourceFiles) -o $(buildDirectory)/$(programName).exe


clean:
	rm -rf $(buildDirectory)/*
	rm -rf *.gz
	rm -rf gmon.out