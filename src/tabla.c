#include "./tabla.h"
#include <stdlib.h>
//metodo para inicializar la pila de tabla de simbolos
void inicia_pila(struct pila_t_simb * pila){
	pila = (struct pila_t_simb *)malloc(sizeof(struct pila_t_simb));
	list_init(pila->pila);
}
//metodo para inicializar una tabla de simbolos
void inicia_ts(struct tabla_simb * tabla){
	tabla = (struct tabla_simb *)malloc(sizeof(struct tabla_simb));
	list_init(tabla->ren);
}
//metodo para inicializar la tabla de tipos
void inicia_tt(struct tabla_tipos * tabla){
	tabla = (struct tabla_tipos *)malloc(sizeof(struct tabla_tipos));
	list_init(tabla->tipos);
}
//mete un elemento tabla de simbolos a la pila de tabla de simbolos especificada
void push_pila(struct pila_t_simb * pila, struct tabla_simb * tabla){
	list_push_front(pila->pila,&(tabla->elem));
}
// obtiene un elemento tabla de simbolos a la pila de tabla de simbolos especificada 
struct tabla_simb * pop_pila(struct pila_t_simb * pila){
	struct list_elem * e = list_pop_front(pila->pila);
	return list_entry (e, struct tabla_simb, elem);
}
//Agrega un renglon especificado a la tabla de simbolos especificada
void agrega_tabla_simb(struct tabla_simb * tabla, struct ren_simb * renglon){
	list_push_front(tabla->ren, &(renglon->elem));
}
//Verfica que exista el lexema especificado en la tabla especificada
int existe_en_ts(struct tabla_simb * tabla, char * lexema){

    struct list_elem *e;
    for (e = list_begin (tabla->ren); e != list_end (tabla->ren);
        e = list_next (e))
    {
        struct ren_simb * f = list_entry (e, struct ren_simb, elem);
        if(f->lexema == lexema){
        	return 1;
        }
    }
    return 0;
}
//Agrega un renglon especificado a la tabla de tipos especificada
void agrega_tabla_tipos(struct tabla_tipos * tabla, struct ren_tipos * renglon){
	list_push_front(tabla->tipos, &(renglon->elem));
}

//Verfica que exista el tipo especificado en la tabla especificada
int existe_en_tt(struct tabla_tipos * tabla, char * tipo){
    struct list_elem *e;
    for (e = list_begin (tabla->tipos); e != list_end (tabla->tipos);
        e = list_next (e))
    {
        struct ren_tipos * f = list_entry (e, struct ren_tipos, elem);
        if(f->tipo == tipo){
        	return 1;
        }
    }
    return 0;
}

//Obtiene un renglon de la tabla de tipos por el campo tipo
struct ren_tipos * obten_ren_tt(struct tabla_tipos * tabla, char * tipo){
    struct list_elem *e;
    for (e = list_begin (tabla->tipos); e != list_end (tabla->tipos);
        e = list_next (e))
    {
        struct ren_tipos * f = list_entry (e, struct ren_tipos, elem);
        if(f->tipo == tipo){
        	return f;
        }
    }
    return NULL;
}

//Obtiene un renglon de la tabla de tipos por el campo tipo
struct ren_simb * obten_ren_ts(struct tabla_simb * tabla, char * lexema){
    struct list_elem *e;
    for (e = list_begin (tabla->ren); e != list_end (tabla->ren);
        e = list_next (e))
    {
        struct ren_simb * f = list_entry (e, struct ren_simb, elem);
        if(f->lexema == lexema){
        	return f;
        }
    }
    return NULL;
}


//libera de la memoria la tabla de tipos especifica
void free_tt(struct tabla_tipos * tabla){
	free(tabla);
}
//libera de la memoria la pila de tabla de simbolos
void free_pila(struct pila_t_simb * pila){
	free_ts(pila->pila);
	free(pila);
}

//libera de la memoria la pila de tabla de simbolos especificada
void free_ts(struct list * lista){
    struct list_elem *e = list_pop_front(lista);
    while(!list_empty(lista)){
    	struct tabla_simb * f = list_entry (e, struct tabla_simb, elem);
    	e = list_next(e);
    	free(f);
    }
}
/*
int main(){
	return 0;
}*/