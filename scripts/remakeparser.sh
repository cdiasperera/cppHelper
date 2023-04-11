#!/bin/bash

# $n = Command line argument n.
# $0 = script name
# $1 = parser name

if [[ -z "$1" ]]; then
    echo "Must provide arg 1 (set num) in environment" 1>&2
    exit 1
fi

Scanner="$1Scanner"
Parser="$1Parser"

cd $Parser
bisonc++ grammar
cd ../$Scanner
flexc++ lexer
cd ..