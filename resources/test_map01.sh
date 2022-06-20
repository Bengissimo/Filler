#!/bin/bash

echo "" > results_map_01

echo "---map01--- player1: bkandemi"

echo "CHAMPELY"

echo "bkandemi(O) against champely(X) map01" >> results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/champely.filler > champely_trace_map_01_$i.txt
   grep "fin" champely_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >> results_map_01
done

echo "ABANLIN"

echo "bkandemi(O) against abanlin(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/abanlin.filler >> abanlin_trace_map_01_$i.txt
   grep "fin" abanlin_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "HCAO"

echo "bkandemi(O) against hcao(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/hcao.filler >> hcao_trace_map_01_$i.txt
   grep "fin" hcao_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "GRATI"

echo "bkandemi(O) against grati(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/grati.filler > grati_trace_map_01_$i.txt
   grep "fin" grati_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "CARLI"

echo "bkandemi(O) against carli(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/carli.filler > carli_trace_map_01_$i.txt
   grep "fin" carli_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "SUPERJEANNOT"

echo "bkandemi(O) against superjeannot(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/superjeannot.filler > superjeannot_trace_map_01_$i.txt
   grep "fin" superjeannot_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "---map01--- player2: bkandemi"

echo "CHAMPELY"

echo "champely(O) against bkandemi(X) map01" >> results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/champely.filler > CHAMPELY_trace_map_01_$i.txt
   grep "fin" CHAMPELY_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >> results_map_01
done

echo "ABANLIN"

echo "abanlin(O) against bkandemi(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/abanlin.filler > ABANLIN_trace_map_01_$i.txt
   grep "fin" ABANLIN_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "HCAO"

echo "hcao(O) against bkandemi(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/hcao.filler > HCAO_trace_map_01_$i.txt
   grep "fin" HCAO_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "GRATI"

echo "grati(O) against bkandemi(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/grati.filler > GRATI_trace_map_01_$i.txt
   grep "fin" GRATI_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "CARLI"

echo "carli(O) against bkandemi(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/carli.filler > CARLI_trace_map_01_$i.txt
   grep "fin" CARLI_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done

echo "SUPERJEANNOT"

echo "superjeannot(O) against bkandemi(X) map01" >>results_map_01
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map01 -p1 players/superjeannot.filler > SUPERJEANNOT_trace_map_01_$i.txt
   grep "fin" SUPERJEANNOT_trace_map_01_$i.txt | tail -2 >>results_map_01
   echo "" >>results_map_01
done