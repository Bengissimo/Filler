#!/bin/bash

echo "" > results_map_01

echo "bkandemi(O) against (X) map01" >> results_map_01
for i in {1..5}; do
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/champely.filler >> champely_trace_map_01_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/abanlin.filler >> abanlin_trace_map_01_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/hcao.filler >> hcao_trace_map_01_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/grati.filler >> grati_trace_map_01_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/carli.filler >> carli_trace_map_01_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map01 -p2 players/superjeannot.filler >> sj_trace_map_01_$i.txt &
done

wait

printf " ###### bkandemi(O) against champely (X) map01  ######  \n\n" >> results_map_01
for i in {1..5}; do
	echo "champely_$i" >> results_map_01
	grep "fin" champely_trace_map_01_$i.txt | tail -2  >> results_map_01
	printf "\n\n" >> results_map_01
done

printf "  ######  bkandemi(O) against abanlin (X) map01 ###### \n\n" >> results_map_01
for i in {1..5}; do
	echo "abanlin_$i" >> results_map_01
	grep "fin" abanlin_trace_map_01_$i.txt | tail -2 >> results_map_01
	printf "\n\n" >> results_map_01
done

printf " ###### bkandemi(O) against hcao (X) map01 ###### \n\n" >> results_map_01
for i in {1..5}; do
	echo "hcao_$i" >> results_map_01
	grep "fin" hcao_trace_map_01_$i.txt | tail -2 >> results_map_01
	printf "\n\n" >> results_map_01
done

printf " ###### bkandemi(O) against grati (X) map01 ###### \n\n" >> results_map_01
for i in {1..5}; do
	echo "grati_$i" >> results_map_01
	grep "fin" grati_trace_map_01_$i.txt | tail -2 >> results_map_01
	printf "\n\n" >> results_map_01
done


printf " ###### bkandemi(O) against carli (X) map01 ###### \n\n" >> results_map_01
for i in {1..5}; do
	echo "carli_$i" >> results_map_01
	grep "fin" carli_trace_map_01_$i.txt | tail -2 >> results_map_01
	printf "\n\n" >> results_map_01
done

printf " ###### bkandemi(O) against sj (X) map01 ###### \n\n" >> results_map_01
for i in {1..5}; do
	echo "sj_$i" >> results_map_01
	grep "fin" sj_trace_map_01_$i.txt | tail -2 >> results_map_01
	printf "\n\n" >> results_map_01
done

echo "map01 ALL DONE"
