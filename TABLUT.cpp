
//------------------------------//
// Desarrollado por: Santiago Rey // PROYECTO INTODRUCCION A LA PROGRAMACIÓN //
//------------------------------//
#include <iostream>
#include <cabeceras.h>
#include <locale.h>
#define FILAS 9
#define COLUMNAS 9
//SUECOS = O +
//MOSCOVITAS = X
using namespace std;

int main(){
	setlocale (LC_CTYPE, "Spanish");

	char tablero[FILAS][COLUMNAS] = {{'-','-','-','X','X','X','-','-','-'}
									,{'-','-','-','-','X','-','-','-','-'}
									,{'-','-','-','-','O','-','-','-','-'}
									,{'X','-','-','-','O','-','-','-','X'}
									,{'X','X','O','O','+','O','O','X','X'}
									,{'X','-','-','-','O','-','-','-','X'}
									,{'-','-','-','-','O','-','-','-','-'}
									,{'-','-','-','-','X','-','-','-','-'}
									,{'-','-','-','X','X','X','-','-','-'}};

	bool turno = true, ganador = false;
	int f = 0, c = 0, fnueva = 0, cnueva = 0;

	f_turnos(ganador, turno, &f, &c, &fnueva, &cnueva, tablero);

	return 0;
}


//----------------------------------------------------------------------------------------------------------
void f_preguntarmov(int *f, int *c, int *fnueva, int *cnueva){
	cout << "¿En que fila y en que columna esta la ficha que quiere mover? (fila y columna) > ";
	cin  >> *f >> *c;
	cout << "¿A que fila y a que columna quiere mover la ficha? (fila y columna) > ";
	cin  >> *fnueva >> *cnueva;
}

//----------------------------------------------------------------------------------------------------------
bool f_validarmov_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = false;

	if(f_limite(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == true){
		if(f_mismo_equipo_suecos(&(*f), &(*c), tablero) == true){
			if(f_pos_fin_ini(&(*f), &(*c), &(*fnueva), &(*cnueva)) == true){
				if(f_mov_hori_verti(&(*f), &(*c), &(*fnueva), &(*cnueva)) == true){
                    if (*cnueva > *c && *fnueva == *f){
                        if(f_mov_derecha(&(*f), &(*fnueva), &(*c), &(*cnueva), tablero) == true){
						retorno = true;
                        }
					}
					if (*cnueva < *c && *fnueva == *f){
                        if(f_mov_izquierda(&(*f), &(*fnueva), &(*c), &(*cnueva), tablero) == true){
                            retorno = true;
                        }
					}
                    if (*fnueva < *f && *cnueva == *c){
                        if(f_mov_arriba(&(*c), &(*cnueva), &(*f), &(*fnueva), tablero) == true){
                            retorno = true;
                        }
                    }
                    if (*fnueva > *f && *cnueva == *c){
                        if(f_mov_abajo(&(*c), &(*cnueva), &(*f), &(*fnueva), tablero) == true){
                            retorno = true;
                        }
                    }
				}
			}
		}
	}

	return retorno;
}

//----------------------------------------------------------------------------------------------------------
bool f_mov_hori_verti(int *f, int *c, int *fnueva, int *cnueva){//4//
	bool retorno = false;

	if(*f == *fnueva || *c == *cnueva){
		retorno = true;
	}else{
		cout << "\nError, el movimiento no es permitido" << endl;
	}

	return retorno;
}

//----------------------------------------------------------------------------------------------------------
bool f_pos_fin_ini(int *f, int *c, int *fnueva, int *cnueva){//3/
	bool retorno = false;

	if(*f != *fnueva || *c != *cnueva){
		retorno = true;
	}else
		cout << "\nError, debe moverse" << endl;

	return retorno;
}

//----------------------------------------------------------------------------------------------------------
bool f_mismo_equipo_suecos(int *f, int *c, char tablero[FILAS][COLUMNAS]){//2//
	bool retorno = false;

	if(tablero[*f][*c] != 'X' && tablero[*f][*c] != '-' && tablero[*f][*c] == 'O' || tablero[*f][*c] == '+'){
		retorno = true;
	}else
		cout << "\nError, la ficha no corresponde a las de su equipo" << endl;

	return retorno;
}

//----------------------------------------------------------------------------------------------------------
bool f_limite(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){ //1/
	bool retorno = false;

	if(*fnueva >= 0 && *fnueva < 9 && *f >= 0 && *f < 9 && *cnueva >= 0 && *cnueva < 9 &&  *c >= 0 && *c < 9){
		retorno = true;
	}else{
		cout << "\nError, supera el limite del tablero" << endl;
	}

	return retorno;
}

//----------------------------------------------------------------------------------------------------------
void f_mov_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){

	if(f_validarmov_suecos(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == true){
		tablero[*f][*c] = '-';
	}
	if(tablero[*f][*c] == '+'){
		tablero[*fnueva][*cnueva] = '+';
	}else
		tablero[*fnueva][*cnueva] = 'O';
}
//----------------------------------------------------------------------------------------------------------
bool f_validarmov_moscovitas(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = false;

	if(f_limite(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == true){
		if(f_mismo_equipo_msvits(&(*f), &(*c), tablero) == true){
			if(f_pos_fin_ini(&(*f), &(*c), &(*fnueva), &(*cnueva)) == true){
				if(f_mov_hori_verti(&(*f), &(*c), &(*fnueva), &(*cnueva)) == true){
                    if (*cnueva > *c && *fnueva == *f){
                        if(f_mov_derecha(&(*f), &(*fnueva), &(*c), &(*cnueva), tablero) == true){
						retorno = true;
                        }
					}
					if (*cnueva < *c && *fnueva == *f){
                        if(f_mov_izquierda(&(*f), &(*fnueva), &(*c), &(*cnueva), tablero) == true){
                            retorno = true;
                        }
					}
                    if (*fnueva < *f && *cnueva == *c){
                        if(f_mov_arriba(&(*c), &(*cnueva), &(*f), &(*fnueva), tablero) == true){
                            retorno = true;
                        }
                    }
                    if (*fnueva > *f && *cnueva == *c){
                        if(f_mov_abajo(&(*c), &(*cnueva), &(*f), &(*fnueva), tablero) == true){
                            retorno = true;
                        }
                    }
				}
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
bool f_mismo_equipo_msvits(int *f, int *c, char tablero[FILAS][COLUMNAS]){//5/
	bool retorno = false;

	if(tablero[*f][*c] != 'O' && tablero[*f][*c] != '-' && tablero[*f][*c] == 'X' && tablero[*f][*c] != '+'){
		retorno = true;
	}else
		cout << "\nError, la ficha no corresponde a las de su equipo" << endl;

	return retorno;
}

//---------------------------------------------------------------------------------------------------------
void f_mov_moscovitas(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){

	if(f_validarmov_moscovitas(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == true){
		tablero[*f][*c] = '-';
		tablero[*fnueva][*cnueva] = 'X';
	}
}
//---------------------------------------------------------------------------------------------------------
void f_turnos(bool ganador, bool turno, int *f, int *c, int *fnueva, int *cnueva, char tablero [FILAS][COLUMNAS]){
    cout << "\n---------TABLERO---------" << endl;
    imprimir_tablero(tablero, FILAS, COLUMNAS);
	while(ganador == false){
		if(turno == true){
			cout << "\nTurno de los suecos" << endl;
			f_preguntarmov (&(*f), &(*c), &(*fnueva), &(*cnueva));
			while (f_validarmov_suecos(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == false){
				cout << "\n>>Intentelo de nuevo<<\n" << endl;
				f_preguntarmov (&(*f), &(*c), &(*fnueva), &(*cnueva));
			}
			f_mov_suecos (&(*f), &(*c), &(*fnueva), &(*cnueva), tablero);
			turno = false;
			capturar_moscovita(&(*fnueva), &(*cnueva), tablero);
			f_raichi (&(*f), &(*c), &(*fnueva), &(*cnueva), tablero);
			f_ganan_suecos(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero, &ganador);
			imprimir_tablero(tablero, FILAS, COLUMNAS);
		}else{
			cout << "\nTurno de los moscovitas" << endl;
			f_preguntarmov (&(*f), &(*c), &(*fnueva), &(*cnueva));
			while (f_validarmov_moscovitas(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero) == false){
				cout << "\n>>Intentelo de nuevo<<\n" << endl;
				f_preguntarmov (&(*f), &(*c), &(*fnueva), &(*cnueva));
			}
			f_mov_moscovitas(&(*f), &(*c), &(*fnueva), &(*cnueva), tablero);
			turno = true;
			capturar_sueco(&(*fnueva), &(*cnueva), tablero, &ganador);
			imprimir_tablero(tablero, FILAS, COLUMNAS);
		}
	}
}

//---------------------------------------------------------------------------------------------------------
bool f_mov_derecha(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = true;

		for (int i = *c + 1; i <= *cnueva; i++){
			if(tablero[*f][i] != '-'){
				retorno = false;
				cout << "\nHay una ficha que impide el movimiento" << endl;
			}
		}

	return retorno;
}

//---------------------------------------------------------------------------------------------------------
bool f_mov_izquierda(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = true;

		for (int i = *c - 1; i >= *cnueva; i--){
			if(tablero[*f][i] != '-'){
				retorno = false;
				cout << "\nHay una ficha que impide el movimiento" << endl;
			}
		}

	return retorno;
}

//---------------------------------------------------------------------------------------------------------
bool f_mov_arriba(int *c, int *cnueva, int *f, int *fnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = true;

		for (int i = *f - 1; i >= *fnueva; i--){
			if(tablero[i][*c] != '-'){
				retorno = false;
				cout << "\nHay una ficha que impide el movimiento" << endl;
			}
		}

	return retorno;
}

//---------------------------------------------------------------------------------------------------------
bool f_mov_abajo(int *c, int *cnueva, int *f, int *fnueva, char tablero[FILAS][COLUMNAS]){
	bool retorno = true;

		for (int i = *f + 1; i <= *fnueva; i++){

			if(tablero[i][*c] != '-'){
				retorno = false;
				cout << "\nHay una ficha que impide el movimiento" << endl;
			}
		}

	return retorno;
}

//------------------------------------------------------------------------------------------------------------
//SANTIAGO DESDE AQUI EMPEZAMOS LA 2DA ENTREGA//

bool f_casillas_rey(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]){
    bool retorno = true;

    if (tablero[*f][*c] == 'O' || tablero[*f][*c] == 'X'){
        if(*fnueva == 4 && *cnueva == 4){
            cout << " No puede mover la ficha a está casilla, porque es el Konakis" << endl;
            retorno = false;
        }
        if((*fnueva == 0 && *cnueva == 0)||(*fnueva == 0 && *cnueva == 8)||
           (*fnueva == 8 && *cnueva == 0)||(*fnueva == 8 && *cnueva == 8)){
            cout << " No puede mover la ficha a está casilla, porque es una de las esquinas del rey" << endl;
            retorno = false;
        }
    }
    return retorno;
}
//------------------------------------------------------------------------------------------------------------
void f_raichi (int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]){
    int i = 0;
    bool dos = false, uno = false;

    if ((*fnueva = 0)||(*fnueva = 8)){
        for(i = *cnueva; i >= 0; i--){
            uno = false;
            if(tablero[*fnueva][i] = '-'){
                uno = true;
            }
        }
        for(i = *cnueva; i < 9; i++){
            dos = false;
            if(tablero[*fnueva][i] = '-'){
                dos = true;
            }
        }
        if( uno == true && dos == true){
            cout << "¡Tuichi!";
        }else if((uno == true && dos == false)||(uno == false && dos == true)){
            cout << "¡Raichi!";
        }
    }

    if ((*cnueva = 0)||(*cnueva = 8)){
        for(i = *fnueva; i >= 0; i--){
            uno = false;
            if(tablero[i][*cnueva] = '-'){
                uno = true;
            }
        }
        for(i = *fnueva; i >= 0; i++){
            dos = false;
            if(tablero[i][*cnueva] = '-'){
                dos = true;
            }
        }
        if( uno == true && dos == true){
            cout << "¡Tuichi!";
        }else if((uno == true && dos == false)||(uno == false && dos == true)){
            cout << "¡Raichi!";
        }
    }
}
//---------------------------------------------------------------------------

void imprimir_tablero(char tablero[FILAS][COLUMNAS], int filas, int colms) {
    int i = 0;

    for (i = 0; i < filas; i ++)
        imprimir_arreglo(tablero[i], colms);
    cout << "------------------------\n";
}
//---------------------------------------------------------------------------
void imprimir_arreglo(char tablero[], int colms) {
    int i = 0;
    cout << "|";
    for (i = 0; i < colms - 1; i++)
        cout << tablero[i] << " ";
    cout << tablero[i] << "|\n";
}
//---------------------------------------------------------------------------
bool f_ganan_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS], bool *ganador){
    bool retorno = false;

    if(tablero[*f][*c] == '+'){
        if((*fnueva == 0 && *cnueva == 0) ||
           (*fnueva == 0 && *cnueva == 8) ||
           (*fnueva == 8 && *cnueva == 0) ||
           (*fnueva == 8 && *cnueva == 8)){
            retorno = true;
            cout << "Rey en esquina!! " << endl;
            cout << "Felicitaciones Suecos, son los ganadores!! " << endl;
            *ganador = true;
           }
    }
    return retorno;
}

void capturar_sueco(int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS], bool *ganador){
    bool peon_eliminado = false;
    bool rey_eliminado = false;
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == 'O' && tablero[*fnueva+2][*cnueva] == 'X' ){
        tablero[*fnueva+1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == 'O' && tablero[*fnueva-2][*cnueva] == 'X' ){
        tablero[*fnueva-1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == 'O' && *fnueva+2 == 8 && (*cnueva == 0 || *cnueva == 8)){
        tablero[*fnueva+1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == 'O' && *fnueva-2 == 0 && (*cnueva == 0 || *cnueva == 8)){
        tablero[*fnueva-1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == 'O' && tablero[*fnueva][*cnueva+2] == 'X' ){
        tablero[*fnueva][*cnueva+1] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == 'O' && tablero[*fnueva][*cnueva-2] == 'X' ){
        tablero[*fnueva][*cnueva-1] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == 'O' && (*fnueva == 0 || *fnueva == 8) && *cnueva+2 == 8){
        tablero[*fnueva][*cnueva+1] = '-';
        peon_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == 'O' && (*fnueva == 0 || *fnueva == 8) && *cnueva-2 == 0){
        tablero[*fnueva][*cnueva-1] = '-';
        peon_eliminado = true;
    }

    //Capturar al rey
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+2][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva-1] == 'X'&& tablero[*fnueva+1][*cnueva+1] == 'X'){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-2][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva+1] == 'X'&& tablero[*fnueva-1][*cnueva-1] == 'X'){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva][*cnueva+2] == 'X' && tablero[*fnueva-1][*cnueva+1] == 'X'&& tablero[*fnueva+1][*cnueva+1] == 'X'){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva][*cnueva-2] == 'X' && tablero[*fnueva-1][*cnueva-1] == 'X'&& tablero[*fnueva+1][*cnueva-1] == 'X'){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    //borde derecho
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva-1][*cnueva+1] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X'){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    //borde superior
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-1][*cnueva+1] == 'X' && tablero[*fnueva-1][*cnueva-1] == 'X'){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //borde izquierdo
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva-1][*cnueva-1] == 'X' && tablero[*fnueva+1][*cnueva-1] == 'X'){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    //borde inferior
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+1][*cnueva-1] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X'){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //esquina superior derecha
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva-1 == 0 && *cnueva+1 == 8){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-1][*cnueva-1] == 'X' && *fnueva-1 == 0 && *cnueva+1 == 8){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //esquina inferior derecha
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva-1][*cnueva+1] == 'X' && *fnueva+1 == 8 && *cnueva+1 == 8){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+1][*cnueva-1] == 'X' && *fnueva+1 == 8 && *cnueva+1 == 8){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }
    //esquina superior izquierda
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva+1][*cnueva-1] == 'X' && *fnueva-1 == 0 && *cnueva-1 == 0){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-1][*cnueva+1] == 'X' && *fnueva-1 == 0 && *cnueva-1 == 0){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //esquina inferior izquierda
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva-1][*cnueva-1] == 'X' && *fnueva+1 == 8 && *cnueva-1 == 0){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva+1 == 8 && *cnueva-1 == 0){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //konakis derecha
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva+1][*cnueva-1] == 'X' && tablero[*fnueva-1][*cnueva-1] == 'X' && *fnueva == 4 && *cnueva-2 == 4){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-2][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva+1] == 'X' && *fnueva-1 == 4 && *cnueva-1 == 4){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+2][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva+1 == 4 && *cnueva-1 == 4){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //konakis izquierda
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva-1][*cnueva+1] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva == 4 && *cnueva+2 == 4){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-2][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva-1] == 'X' && *fnueva-1 == 4 && *cnueva+1 == 4){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+2][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva-1] == 'X' && *fnueva+1 == 4 && *cnueva+1 == 4){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    //konakis superior
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva+1][*cnueva] == '+' && tablero[*fnueva+1][*cnueva-1] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva+2 == 4 && *cnueva == 4){
        tablero[*fnueva+1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva][*cnueva+2] == 'X' && tablero[*fnueva-1][*cnueva+1] == 'X' && *fnueva+1 == 4 && *cnueva+1 == 4){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva][*cnueva-2] == 'X' && tablero[*fnueva-1][*cnueva-1] == 'X' && *fnueva+1 == 4 && *cnueva-1 == 4){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }

    //konakis inferior
    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva-1][*cnueva] == '+' && tablero[*fnueva-1][*cnueva-1] == 'X' && tablero[*fnueva-1][*cnueva+1] == 'X' && *fnueva-2 == 4 && *cnueva == 4){
        tablero[*fnueva-1][*cnueva] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva+1] == '+' && tablero[*fnueva][*cnueva+2] == 'X' && tablero[*fnueva+1][*cnueva+1] == 'X' && *fnueva-1 == 4 && *cnueva+1 == 4){
        tablero[*fnueva][*cnueva+1] = '-';
        rey_eliminado = true;
    }

    if(tablero[*fnueva][*cnueva] == 'X' && tablero[*fnueva][*cnueva-1] == '+' && tablero[*fnueva][*cnueva-2] == 'X' && tablero[*fnueva+1][*cnueva-1] == 'X' && *fnueva-1 == 4 && *cnueva-1 == 4){
        tablero[*fnueva][*cnueva-1] = '-';
        rey_eliminado = true;
    }
    if(peon_eliminado){
        cout << "peon SUECO capturado!! " << endl;
    }
    if(rey_eliminado){
        cout << "Rey capturado!! " << endl;
        cout << "Felicitaciones Moscovitas, son los ganadores!! " << endl;
        *ganador = true;
    }
}
void capturar_moscovita(int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]){
    bool peon_eliminado = false;
    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva+1][*cnueva] == 'X' && tablero[*fnueva+2][*cnueva] == 'O' ){
        tablero[*fnueva+1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva-1][*cnueva] == 'X' && tablero[*fnueva-2][*cnueva] == 'O' ){
        tablero[*fnueva-1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva+1][*cnueva] == 'X' && *fnueva+2 == 8 && (*cnueva == 0 || *cnueva == 8)){
        tablero[*fnueva+1][*cnueva] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva-1][*cnueva] == 'X' && *fnueva-2 == 0 && (*cnueva == 0 || *cnueva == 8)){
        tablero[*fnueva-1][*cnueva] == '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva][*cnueva+1] == 'X' && tablero[*fnueva][*cnueva+2] == 'O' ){
        tablero[*fnueva][*cnueva+1] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva][*cnueva-1] == 'X' && tablero[*fnueva][*cnueva-2] == 'O' ){
        tablero[*fnueva][*cnueva-1] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva][*cnueva+1] == 'X' && (*fnueva == 0 || *fnueva == 8) && *cnueva+2 == 8){
        tablero[*fnueva][*cnueva+1] = '-';
        peon_eliminado = true;
    }

    if((tablero[*fnueva][*cnueva] == 'O' || tablero[*fnueva][*cnueva] == '+') && tablero[*fnueva][*cnueva-1] == 'X' && (*fnueva == 0 || *fnueva == 8) && *cnueva-2 == 0){
        tablero[*fnueva][*cnueva-1] = '-';
        peon_eliminado = true;
    }
    if(peon_eliminado){
        cout << "peon MOSCOVITA capturado!! " << endl;
    }
}

