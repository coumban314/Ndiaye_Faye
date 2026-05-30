all:
	gcc main.c tableau_statique.c patient.c consultation.c liste_chainee.c abr.c tas.c -I include -o test

clean:
	rm -f test