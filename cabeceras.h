#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED

//----------------------------------------------------------------------------------------------------------
void f_imprimir_tablero_inicial(char tablero[FILAS][COLUMNAS]);
void f_turnos(bool ganador, bool turno, int *f, int *c, int *fnueva, int *cnueva, char tablero [FILAS][COLUMNAS]);
void f_preguntarmov(int *f, int *c, int *fnueva, int *cnueva);
bool f_validarmov_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
bool f_validarmov_moscovitas(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
void f_mov_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
void f_mov_moscovitas(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
bool f_mov_derecha(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]);
bool f_mov_izquierda(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]);
bool f_mov_arriba(int *c, int *cnueva, int *f, int *fnueva, char tablero[FILAS][COLUMNAS]);
bool f_mov_abajo(int *c, int *cnueva, int *f, int *fnueva, char tablero[FILAS][COLUMNAS]);
bool f_limite(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
bool f_mismo_equipo_suecos(int *f, int *c, char tablero[FILAS][COLUMNAS]);
bool f_pos_fin_ini(int *f, int *c, int *fnueva, int *cnueva);
bool f_mov_hori_verti(int *f, int *c, int *fnueva, int *cnueva);
bool f_mismo_equipo_msvits(int *f, int *c, char tablero[FILAS][COLUMNAS]);
bool f_rey_en_trono (char tablero [FILAS][COLUMNAS]);
bool f_casillas_rey(int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]);
void f_raichi (int *f, int *fnueva, int *c, int *cnueva, char tablero[FILAS][COLUMNAS]);
void imprimir_tablero(char tablero[FILAS][COLUMNAS], int filas, int colms);
void imprimir_arreglo(char tablero[], int colms);
bool f_ganan_suecos(int *f, int *c, int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS], bool *ganador);
void capturar_sueco(int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS], bool *ganador);
void capturar_moscovita(int *fnueva, int *cnueva, char tablero[FILAS][COLUMNAS]);
void imprimirTablero(char tablero[FILAS][COLUMNAS]);
//----------------------------------------------------------------------------------------------------------

#endif // CABECERAS_H_INCLUDED
