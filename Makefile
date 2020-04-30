CXX = g++
CXXFLAGS = -c -Ihh -Icpp -Wall -Werror -Wextra -pedantic -std=c++17 -g
OBJ = obj/dijkstra.o obj/graf_l.o obj/graf_m.o obj/kopiec.o obj/lista_2_kier.o obj/losowanie_grafu.o obj/wektor.o

__start__: szukanie_sciezki
	

szukanie_sciezki: obj obj/main.o $(OBJ)
	g++ -Wall -Werror -Wextra -pedantic -std=c++17 -o szukanie_sciezki obj/main.o $(OBJ)

obj: 
	mkdir obj

obj/main.o: src/main.cpp src/inc/dijkstra.hh src/inc/graf_m.hh src/inc/graf_l.hh src/inc/losowanie_grafu.hh
	$(CXX) ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/wektor.o: src/wektor.cpp src/inc/wektor.hh
	$(CXX) ${CXXFLAGS} -o obj/wektor.o src/wektor.cpp

obj/losowanie_grafu.o: src/losowanie_grafu.cpp src/inc/losowanie_grafu.hh
	$(CXX) ${CXXFLAGS} -o obj/losowanie_grafu.o src/losowanie_grafu.cpp

obj/lista_2_kier.o: src/lista_2_kier.cpp src/inc/lista_2_kier.hh
	$(CXX) ${CXXFLAGS} -o obj/lista_2_kier.o src/lista_2_kier.cpp

obj/graf_l.o: src/graf_l.cpp src/inc/graf_l.hh src/inc/element_l.hh src/inc/lista_2_kier.hh
	$(CXX) ${CXXFLAGS} -o obj/graf_l.o src/graf_l.cpp

obj/graf_m.o: src/graf_m.cpp src/inc/graf_m.hh src/inc/element_m.hh src/inc/lista_2_kier.hh
	$(CXX) ${CXXFLAGS} -o obj/graf_m.o src/graf_m.cpp

obj/kopiec.o: src/kopiec.cpp src/inc/kopiec.hh src/inc/wektor.hh
	$(CXX) ${CXXFLAGS} -o obj/kopiec.o src/kopiec.cpp

obj/dijkstra.o: src/dijkstra.cpp src/inc/dijkstra.hh src/inc/graf_l.hh src/inc/graf_m.hh src/inc/kopiec.hh
	$(CXX) ${CXXFLAGS} -o obj/dijkstra.o src/dijkstra.cpp

obj/driver.o: src/driver.cpp src/inc/dijkstra.hh src/inc/graf_m.hh src/inc/graf_l.hh src/inc/losowanie_grafu.hh
	$(CXX) ${CXXFLAGS} -o obj/driver.o src/driver.cpp

clean:
	rm -f obj/*.o szukanie_sciezki driver test_dij

driver: obj obj/driver.o $(OBJ)
	g++ -Wall -Werror -Wextra -pedantic -std=c++17 -o driver obj/driver.o $(OBJ)
	./driver
	