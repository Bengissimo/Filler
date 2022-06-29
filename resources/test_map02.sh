#!/bin/bash

echo "" > results_map_02

echo "bkandemi(O) against (X) map02" >> results_map_02
for i in {1..5}; do
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/champely.filler >> champely_trace_map_02_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/abanlin.filler >> abanlin_trace_map_02_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/hcao.filler >> hcao_trace_map_02_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/grati.filler >> grati_trace_map_02_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/carli.filler >> carli_trace_map_02_$i.txt &
	./filler_vm -p1 ../bkandemi.filler -v -f maps/map02 -p2 players/superjeannot.filler >> sj_trace_map_02_$i.txt &
done

wait 

printf " ###### bkandemi(O) against champely (X) map02  ######  \n\n" >> results_map_02
for i in {1..5}; do
	echo "champely_$i" >> results_map_02
	grep "fin" champely_trace_map_02_$i.txt | tail -2  >> results_map_02
	printf "\n\n" >> results_map_02
done

printf "  ######  bkandemi(O) against abanlin (X) map02 ###### \n\n" >> results_map_02
for i in {1..5}; do
	echo "abanlin_$i" >> results_map_02
	grep "fin" abanlin_trace_map_02_$i.txt | tail -2 >> results_map_02
	printf "\n\n" >> results_map_02
done

printf " ###### bkandemi(O) against hcao (X) map02 ###### \n\n" >> results_map_02
for i in {1..5}; do
	echo "hcao_$i" >> results_map_02
	grep "fin" hcao_trace_map_02_$i.txt | tail -2 >> results_map_02
	printf "\n\n" >> results_map_02
done

printf " ###### bkandemi(O) against grati (X) map02 ###### \n\n" >> results_map_02
for i in {1..5}; do
	echo "grati_$i" >> results_map_02
	grep "fin" grati_trace_map_02_$i.txt | tail -2 >> results_map_02
	printf "\n\n" >> results_map_02
done


printf " ###### bkandemi(O) against carli (X) map02 ###### \n\n" >> results_map_02
for i in {1..5}; do
	echo "carli_$i" >> results_map_02
	grep "fin" carli_trace_map_02_$i.txt | tail -2 >> results_map_02
	printf "\n\n" >> results_map_02
done

printf " ###### bkandemi(O) against sj (X) map02 ###### \n\n" >> results_map_02
for i in {1..5}; do
	echo "sj_$i" >> results_map_02
	grep "fin" sj_trace_map_02_$i.txt | tail -2 >> results_map_02
	printf "\n\n" >> results_map_02
done

echo "map02 ALL DONE"
