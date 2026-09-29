# COS214_Prac5
Christian Khaled u25420314
Haytham Phillips u25030907
Nico Sibiya u24667642

Docker Instructions:

Clone the repository
	git clone https://github.com/HaythamP/COS214_Prac5
And then cd into it.

Build and run the full docker application:
	docker compose up --build

Stop and remove the container afterwards:
	docker compose down

Run valgrind inside the docker environment:
	docker compose run --rm campusguard valgrind --leak-check=full --show-leak-kinds=all--track-origins=yes ./campusguard

Run gdb inside of docker environment
docker compose run --rm campusguard gdb ./campusguard

Makefile instructions
make - builds the campusguard
make run - builds and runs it
make valgrind - builds and runs it through valgrind
make clean - removes and cleans all of the builds.


