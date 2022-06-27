#!/bin/bash

echo "" > results_map_00

echo "bkandemi(O) against (X) map00" >> results_map_00
for i in {1..5}; do
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/champely.filler > champely_trace_map_00_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map00 -p2 players/abanlin.filler >> abanlin_trace_map_00_$i.txt &
done

wait 
for i in {1..5}; do
	echo "champely_$i" >> results_map_00
	grep "fin" champely_trace_map_00_$i.txt | tail -2  | echo "" >> results_map_00
	echo "abanlin_$i" >> results_map_00
	grep "fin" abanlin_trace_map_00_$i.txt | tail -2 >> results_map_00
	echo "hcao_$i" >> results_map_00
	grep "fin" hcao_trace_map_00_$i.txt | tail -2 >> results_map_00
	echo "grati_$i" >> results_map_00
	grep "fin" grati_trace_map_00_$i.txt | tail -2 >> results_map_00
	echo "carli_$i" >> results_map_00
	grep "fin" carli_trace_map_00_$i.txt | tail -2 >> results_map_00
	echo "sj_$i" >> results_map_00
	grep "fin" sj_1_trace_map_00_$i.txt | tail -2 >> results_map_00

done

echo "ALL DONE"
