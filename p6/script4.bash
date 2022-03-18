#!/bin/bash
echo "*******Environment variables start*******"
printenv
echo "*******Environment variables end*******"
echo "*******Command line arguments start*******"
for i in $*; do  
  echo $i  
done 
echo "*******Command line arguments end*******"