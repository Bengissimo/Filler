#!/bin/bash

echo "" > results_map_00

echo "---MAP00--- player1: bkandemi"

echo "CHAMPELY"

echo "bkandemi(O) against champely(X) map00" >> results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/champely.filler > champely_trace_map_00_$i.txt
   grep "fin" champely_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >> results_map_00
done

echo "ABANLIN"

echo "bkandemi(O) against abanlin(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/abanlin.filler >> abanlin_trace_map_00_$i.txt
   grep "fin" abanlin_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "HCAO"

echo "bkandemi(O) against hcao(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/hcao.filler >> hcao_trace_map_00_$i.txt
   grep "fin" hcao_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "GRATI"

echo "bkandemi(O) against grati(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/grati.filler > grati_trace_map_00_$i.txt
   grep "fin" grati_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "CARLI"

echo "bkandemi(O) against carli(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/carli.filler > carli_trace_map_00_$i.txt
   grep "fin" carli_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "SUPERJEANNOT"

echo "bkandemi(O) against superjeannot(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/superjeannot.filler > superjeannot_trace_map_00_$i.txt
   grep "fin" superjeannot_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "---MAP00--- player2: bkandemi"

echo "CHAMPELY"

echo "champely(O) against bkandemi(X) map00" >> results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/champely.filler > champley_1_trace_map_00_$i.txt
   grep "fin" champley_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >> results_map_00
done

echo "ABANLIN"

echo "abanlin(O) against bkandemi(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/abanlin.filler > abanlin_1_trace_map_00_$i.txt
   grep "fin" abanlin_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "HCAO"

echo "hcao(O) against bkandemi(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/hcao.filler > hcao_1_trace_map_00_$i.txt
   grep "fin" hcao_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "GRATI"

echo "grati(O) against bkandemi(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/grati.filler > grati_1_trace_map_00_$i.txt
   grep "fin" grati_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "CARLI"

echo "carli(O) against bkandemi(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/carli.filler > carli_1_trace_map_00_$i.txt
   grep "fin" carli_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done

echo "SUPERJEANNOT"

echo "superjeannot(O) against bkandemi(X) map00" >>results_map_00
for i in {1..5}; do
   ./filler_vm -p2 ../bkandemi.filler -v -f maps/map00 -p1 players/superjeannot.filler > sj_1_trace_map_00_$i.txt
   grep "fin" sj_1_trace_map_00_$i.txt | tail -2 >>results_map_00
   echo "" >>results_map_00
done