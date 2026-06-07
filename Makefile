all:
	gcc main.c tableau_statique.c patient.c consultation.c tableau_dynamique.c -o test

clean:
	rm -f test