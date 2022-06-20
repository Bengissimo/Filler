#!/bin/bash

echo "" > results_map_02

echo "---map02--- player1: bkandemi"

echo "CHAMPELY"

echo "bkandemi(O) against champely(X) map02" >> results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/champely.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >> results_map_02
done

echo "ABANLIN"

echo "bkandemi(O) against abanlin(X) map02" >>results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/abanlin.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >>results_map_02
done

echo "HCAO"

echo "bkandemi(O) against hcao(X) map02" >>results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/hcao.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >>results_map_02
done

echo "GRATI"

echo "bkandemi(O) against grati(X) map02" >>results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/grati.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >>results_map_02
done

echo "CARLI"

echo "bkandemi(O) against carli(X) map02" >>results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/carli.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >>results_map_02
done

echo "SUPERJEANNOT"

echo "bkandemi(O) against superjeannot(X) map02" >>results_map_02
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/superjeannot.filler > game_trace_map_02.txt
   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
   echo "" >>results_map_02
done

#echo "---map02--- player2: bkandemi"
#
#echo "CHAMPELY"
#
#echo "champely(O) against bkandemi(X) map02" >> results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/champely.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >> results_map_02
#done
#
#echo "ABANLIN"
#
#echo "abanlin(O) against bkandemi(X) map02" >>results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/abanlin.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >>results_map_02
#done
#
#echo "HCAO"
#
#echo "hcao(O) against bkandemi(X) map02" >>results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/hcao.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >>results_map_02
#done
#
#echo "GRATI"
#
#echo "grati(O) against bkandemi(X) map02" >>results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/grati.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >>results_map_02
#done
#
#echo "CARLI"
#
#echo "carli(O) against bkandemi(X) map02" >>results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/carli.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >>results_map_02
#done
#
#echo "SUPERJEANNOT"
#
#echo "superjeannot(O) against bkandemi(X) map02" >>results_map_02
#for i in {1..5}; do
#   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map02 -p1 players/superjeannot.filler > game_trace_map_02.txt
#   grep "fin" game_trace_map_02.txt | tail -2 >>results_map_02
#   echo "" >>results_map_02
#done