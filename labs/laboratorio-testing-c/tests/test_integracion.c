#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void)
{
    Carrito c;
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_init(&c);
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);
    ASSERT_IGUAL(1300, carrito_total(&c));

    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void)
{
    Carrito c;
    Producto agua = {"Agua", 200, 1};

    carrito_init(&c);
    carrito_agregar(&c, agua);
    carrito_agregar(&c, agua);
    carrito_agregar(&c, agua);
    carrito_agregar(&c, agua);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, agua));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void)
{
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
